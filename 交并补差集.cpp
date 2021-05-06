/*************************************************************************
	> File Name: 交并补差集.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Wed 18 Nov 2020 12:04:55 AM CST
 ************************************************************************/


#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
//集合的交集、并集运算
string quchong(string str)          //字符串去重
{
	if(str.size()<2)   return str;
	string tmp_str("\0");
	tmp_str += str[0];
	string::size_type j;
	for(string::size_type i=1 ; i<str.size() ; i++)
	{
		for(j=0 ; j<tmp_str.size() ; j++)
			if(tmp_str[j]==str[i])  break;
		if(j==tmp_str.size())   tmp_str+=str[i];
	}
	return tmp_str;
}
//集合的差集、补集运算
string quziji(string str,string temp)      //字符串去子集
{
    string result ;
    for (int i = 0; i < str.size(); i++)
    {
        int flag = 0;
        for (int j =0;j < temp.size();j++)
            if (temp[j] == str[i])  flag = 1;
        if (flag == 0)  result += str[i];
    }
    return result;
}

int main()
{
    int choice;
    printf("若求交集、并集输入1，若求差集输入2，请输入：");
    cin>>choice;
    string str1,str2,str3;
    char temp[128];
    int len1,len2,num=0,k;
    cout<<"请输入集合1:";
    cin>>str1;
    cout<<"请输入集合2:";
    cin>>str2;
    len1 = str1.length();
    len2 = str2.length();
    str3 = str1 + str2;

    for(int i = 0;i < len1; i++)
        for(int j = 0;j < len2 ; j++)
            if(str1[i] == str2[j]) temp[num++]=str1[i];
    temp[num] = '\0';

    if(choice == 1) cout<<"两集合交集为:"<<quchong(temp)<<endl;
    if(choice == 1) cout<<"两集合并集为:"<<quchong(str3)<<endl;
    if(choice == 2)
    {
        cout<<"集合1对集合2的差集:"<<quchong(quziji(str1,quchong(temp)))<<endl;
        cout<<"集合2对集合1的差集:"<<quchong(quziji(str2,quchong(temp)))<<endl;
    }
}
