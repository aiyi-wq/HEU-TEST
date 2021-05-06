/*************************************************************************
	> File Name: 幂集.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Wed 18 Nov 2020 12:10:04 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include <iostream>
using namespace std;
char *result;
char *element;
void OutputPowerSet(int len){ //输出幂集中的元素 
	cout<<"{ ";
	int eln = 0;
	for(int i = 0; i < len; i++){
		if(result[i] != 0)
		{
			if(eln > 0)
				cout << "," << result[i];
			else
				cout << result[i];
			eln++;	
		}
	}
	cout<<" }" << endl;
}
void PowerSet(int k,int n){
	if(k > n)
	{
		OutputPowerSet(n);
	}else{
		result[k-1] = element[k-1]; //元素在幂集元素集合中 
		PowerSet(k+1,n);
		result[k-1] = 0;//元素不在幂集元素集合中 
		PowerSet(k+1,n);
	}
}
int main(){
	int num;
	cin>>num;		//输出要求幂集的初始集合元素个数 
	element = new char[num];
	result = new char[num];
	int index = 0;
	while(index < num){
		cin>>element[index];  //输入集合元素，这里用字符代替 
		index++;
	}
	PowerSet(1,num);
} 
