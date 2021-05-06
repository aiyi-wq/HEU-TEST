/*************************************************************************
	> File Name: 命题真值.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Tue 17 Nov 2020 11:58:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class PQ{
	int p,q;
	public:
		PQ(int a=0,int b=0)
		{
			p=a;
			q=b;
		}
		void hequ()
		{
			if(p==1&&q==1)
			cout<<"P和Q合取的真值为1"<<endl;
			else
			cout<<"P和Q合取的真值为0"<<endl; 
		}
		void qixu()
		{
			if(p==0&&q==0)
			cout<<"P和Q析取的真值为0"<<endl;
			else
			cout<<"P和Q析取的真值为1"<<endl;
		}
		void tiaojian()
		{
			if(p==1&&q==0)
			cout<<"p和q的条件真值为0"<<endl;
			else
			cout<<"P和q的条件真值为1"<<endl; 
		}
		void doujian()
		{
			if(p==q)
			cout<<"p和q的双条件真值为1"<<endl;
			else
			cout<<"p和q的双条件真值为0"<<endl; 
		}
}; 
int main()
{
	int a,b;
	cin>>a>>b;
	PQ obj(a,b);
	obj.hequ();
	obj.qixu();
	obj.tiaojian();
	obj.doujian();
	return 0; 
	
}
