/*************************************************************************
	> File Name: 随机点名.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 10 Oct 2020 10:03:31 AM CST
 ************************************************************************/

#include<iostream>
#include<time.h>
using namespace std;
#define max_n 6

char name[max_n][20] = {"艾艺", "习宇航", "车守恒", "刘杏华", "杨静忠", "陈泰铮"};
int flag[max_n] = {0};
void output_name(int n) {
	srand(time(0));
    printf("CEO\tCOO\tCHO\tCTO\t员工1\t员工2\n");
	for (int i = 0; i < n;) {
		int index = rand() % max_n;
		if (flag[index]) continue;
		printf("%s\t", name[index]);
		flag[index] = 1, i++;
	}
	printf("\n");
	return ;
}

int str_to_int(char *str) {
	int cnt = 0;
	for (int i = 0; str[i]; i++) {
		cnt = cnt * 10 + str[i] - '0';
	}
	return cnt;
}

int main(int argc, char *argv[]) {
	char str[3] = {0};
	if (argc < 2) {
        output_name(1);
	} else {
		sprintf(str, "%s", argv[1]);
		int n = str_to_int(str);
		if (n > max_n) {
			printf("最多%d个\n", max_n);
			exit(0);
		}
		output_name(n);
	}
	return 0;
}
