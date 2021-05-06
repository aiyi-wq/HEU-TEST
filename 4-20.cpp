/*************************************************************************
	> File Name: 4-20.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Mon 02 Nov 2020 09:33:44 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
int a[1000];
int n, ans = 1;
int main() {
    cin >> n;
    if (n <= 2) {
        printf("1\n");
        return 0;
    } else if (n <= 4) {
        printf("%d\n", n - 1);
        return 0;
    }
    int sum=0,l=0,left;
    for (int i=2;i<=n;i++) {
        a[l++]=i;
        sum+=i;
        if(sum>n)
        {
            sum-=i,l--,left=n-sum;
            break;
        }
    }
    for(int i=l-1;left;left--)
    {
        a[i]++;
        i--;
        if(i<0) i=l-1;
    }
    for(int i=0;i<=l-1;i++) {
        ans *= a[i];
    }
    printf("%d\n", ans);
    return 0;
}
