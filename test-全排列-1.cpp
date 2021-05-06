/*************************************************************************
	> File Name: test-全排列-1.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Aug 2020 07:54:04 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m, cnt = 1, num[15], mark[15];

void p() {
    for (int i = 1; i <= m; i++) {
        if (i != 1) {
            cout << " ";
        }
        cout << num[i];
    }
    cout << endl;
}

void func(int left) {
    if (left == 0) {
        p();
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            num[cnt++] = i;
            func(left - 1);
            cnt--;
            mark[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    func(m);
    return 0;
}
