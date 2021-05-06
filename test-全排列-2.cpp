/*************************************************************************
	> File Name: test-全排列-2.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Aug 2020 08:16:39 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, num[15], mark[15], cnt = 1;

void p() {
    for (int i = 1; i <= cnt; i++) {
        if (i != 1) {
            cout << " ";
        }
        cout << num[i];
    }
    cout << endl;
}

void func(int start, int left) {
    if (left == 0) {
        p();
        return ;
    }
    for (int i = start; i <= n - left + 1; i++) {
        num[cnt] = i;
        func(i, left - 1);
        cnt--;
    }
}

int main() {
    cin >> n;
    func(1, n);
    return 0;
}
