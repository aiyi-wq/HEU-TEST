/*************************************************************************
	> File Name: 公式真值表.c
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Tue 17 Nov 2020 11:38:32 PM CST
 ************************************************************************/

/*
符号注记：
  +    *     -      ->      <->      T     F
合取  析取   非   单条件  双条件   true  false 
 
运用的方法：
1.将中缀表达式转换为后缀表达式便于计算 
2.DFS二进制枚举每个状态并用后缀表达式求值,得到真值表
3.根据真值表打印主析取函数和主合取函数
修改：
1.0 修改增加了条件和双条件符号的判定
2.0 修改了将“T”和“F”也作为命题变元判定的错误
(结尾附样例输入输出） 
*/ 
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<map>
#include<stack>
#define go(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)
#define ll long long
#define N 10005
#define MOD 1000000007
using namespace std;
 
char s[N];
char a[N];
map<ll,int>m;
stack<char> stk;
void workit1(){
	while (!stk.empty()) stk.pop();
	int len=strlen(s), k=0;
	go(i,0,len-1){
		if (s[i]>='A'&&s[i]<='Z'){ 
			a[k++]=s[i];
		}
		else if (s[i]==')'){ 
			while (stk.top()!='('){
				a[k++]=stk.top();
				stk.pop();
			}
			stk.pop();
		}
		else{ 
			if (s[i]=='-'&&s[i]!='>'){
				while (!stk.empty()&&stk.top()=='-'){
					a[k++]=stk.top();
					stk.pop();
				}
				stk.push(s[i]);
				continue;
			}
			else if (s[i]=='<'){ 
				while (!stk.empty()&&stk.top()!='('){
					a[k++]=stk.top();
					stk.pop();
				}
				stk.push(s[i]);
				i+=2;
			}
			else if (s[i]=='-'&&s[i+1]=='>'){ 
				while (!stk.empty()&&stk.top()=='>'||stk.top()=='+'||stk.top()=='*'||stk.top()=='-'){
					a[k++]=stk.top();
					stk.pop();
				}
				stk.push(s[i+1]);
				i++;
			}
			else if (s[i]=='+'){
				while (!stk.empty()&&stk.top()=='+'||stk.top()=='*'||stk.top()=='-'){
					a[k++]=stk.top();
					stk.pop();
				}
				stk.push(s[i]);
			} 
			else if (s[i]=='*'){
				while (!stk.empty()&&stk.top()=='*'||stk.top()=='-'){
					a[k++]=stk.top();
					stk.pop();
				}
			stk.push(s[i]);
			}
			else stk.push(s[i]);
		}
	}
	while (!stk.empty()){
		a[k++]=stk.top();
		stk.pop();
	}
	a[k]='\0';
}
bool ans[10000005];
char ch[30];
bool h[30];
int f[30],nt[30];
stack<int>stkn;
int dfs(int now, int p, int top){
	if (now==top+1){
		while (!stkn.empty()) stkn.pop();
		int len=strlen(a);
		go(i,0,len-1){
			if (a[i]<='Z'&&a[i]>='A'){
				int x=a[i]-'A';
				if (x+'A'=='T') x=1;
				else if (x+'A'=='F') x=0;
				else x=((p&(1<<(top-f[x])))!=0);
				stkn.push(x);
			}
			else if (a[i]=='-'){
				int x=(stkn.top()==0);
				stkn.pop();
				stkn.push(x);
			}
			else if (a[i]=='*'){
				int x=stkn.top();stkn.pop();
				x=(x==1&&stkn.top()==1); stkn.pop();
				stkn.push(x);
			}
			else if (a[i]=='+'){
				int x=stkn.top();stkn.pop();
				x=(x==1||stkn.top()==1); stkn.pop();
				stkn.push(x);
			}
			else if (a[i]=='>'){
				int x=stkn.top();stkn.pop();
				x=(!(x==0&&stkn.top()==1)); stkn.pop();
				stkn.push(x);
			}
			else if (a[i]=='<'){
				int x=stkn.top();stkn.pop(); 
				x=(x==stkn.top()); stkn.pop();
				stkn.push(x);
			}
		}
		ans[p]=stkn.top();
		return stkn.top();
	}
	int a[2];
	go (i,0,1){
		a[i]=dfs(now+1,p*2+i,top);
	}
	if (a[0]==2||a[1]==2) return 2;
	else if (a[1]!=a[2]) return 2;
	else return a[1];
}
void workit2(){
	memset(h,false,sizeof(h));
	int len=strlen(s);
	go(i,0,len-1){
		if (s[i]<='Z'&&s[i]>='A') h[s[i]-'A']=true;
	}
	int tot=0;
	go(i,0,26){
		if (h[i]&&i+'A'!='F'&&i+'A'!='T') {
			f[i]=++tot;
			nt[tot]=i;
			printf("  %c  ",i+'A');
		}
	}
	printf("  ANS  \n");
	int hb=dfs(1,0,tot);
	go(i,0,(1<<tot)-1){
		for (int j=tot-1;j>=0;j--){
			if ((i&(1<<j))>0) printf("  1  ");
			else printf("  0  ");
		}
		printf("   %d\n",ans[i]);
	}
	if (hb==0||tot==0) printf("NO PDNF\n");
	else{
		printf("PDNF:");
		bool flag=false;
		go(i,0,(1<<tot)-1){
			if (ans[i]==0) continue;
			if (flag) printf("+");
			flag=true;
			printf("(");
			for (int j=tot-1;j>=0;j--){
				if (j!=tot-1) printf("*");
				if ((i&(1<<j))>0) printf("%c",nt[tot-j]+'A');
				else printf("-%c",nt[tot-j]+'A');
			}
			printf(")");
		}
		printf("\n");
	}
	if (hb==1||tot==0) printf("NO PCNF\n");
	else {
		printf("PCNF:");
		bool flag=false;
		go(i,0,(1<<tot)-1){
			if (ans[i]==1) continue;
			if (flag) printf("*");
			flag=true;
			printf("(");
			for (int j=tot-1;j>=0;j--){
				if (j!=tot-1) printf("+");
				if ((i&(1<<j))==0) printf("%c",nt[tot-j]+'A');
				else printf("-%c",nt[tot-j]+'A');
			}
			printf(")");
		}
		printf("\n");
	}
	return ;
}
int main(){
	scanf("%s",s);
	workit1();
	//printf("%s\n",a);
	workit2();
}
/*
INPUT1:  -((P+Q)*P)
OUTPUT1: 
  P    Q    ANS
  0    0     1
  0    1     1
  1    0     0
  1    1     0
PDNF:(-P*-Q)+(-P*Q)
PCNF:(-P+Q)*(-P+-Q)
INPUT2: P*Q+R
OUTPUT2:
  P    Q    R    ANS
  0    0    0     0
  0    0    1     1
  0    1    0     0
  0    1    1     1
  1    0    0     0
  1    0    1     1
  1    1    0     1
  1    1    1     1
PDNF:(-P*-Q*R)+(-P*Q*R)+(P*-Q*R)+(P*Q*-R)+(P*Q*R)
PCNF:(P+Q+R)*(P+-Q+R)*(-P+Q+R)
INPUT1:T<->T
OUTPUT2:
  ANS
   1
NO PDNF
NO PCNF
*/
