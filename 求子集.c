/*************************************************************************
	> File Name: 求子集.c
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Wed 18 Nov 2020 12:17:04 AM CST
 ************************************************************************/

//子集
//对输入的任意正整数n，打印出集合{0,1,2,……,n-1}的所有子集
//例如：输入3时，输出是：{}{0}{1}{2}{0,1}{0,2}{1,2}{0,1,2} --8个，2^3个子集
//{1,2,3}--{1,1,1}
//{1,2}--{1,1,0}
//二进制
#include<stdio.h>
#include<math.h>
int main() {
	int num,i,j,k,m,n;//int范围--2^31 第一位是符号位 
	int a[32]= {0}; //不能根据输入的n定义数组的大小，初始化一个尽可能大的数字
	scanf("%d",&n);//int 2^31 所以n最大值为？ 
	num=pow(2,n);//n个元素有2^n个子集 
	for(k=0; k<num; k++) {
		for(j=0;j<n;j++){//每次初始化为0
			a[j]=0;
		}
		//把k用二进制表示--对2取余
		i=0;
		m=k;
		while(m!=0){
			a[i]=m%2;
			m=m/2;
			i++;
		} 
		printf("{");
		i=0;
		while(i<n) {
			if(a[i]==1){
				printf("%d ",i);//下标代表元素 
			}
			i++;
		}
		printf("}\n");
	}
	return 0;
}
