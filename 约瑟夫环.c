/*************************************************************************
	> File Name: 约瑟夫环.c
	> Author: 
	> Mail: 
	> Created Time: Mon 12 Oct 2020 09:40:30 PM CST
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void joseph(int, int);

int main() {
    int count; //总人数
    int doom; //厄运数
    long startTime;
    long endTime;
    long deltaTime;

    printf("请输入总人数、厄运数: \n");
    scanf("%d %d", &count, &doom);

    startTime = clock();
    // clock()函数能取得从程序开始运行到执行该函数时所经过的毫秒数
    joseph(count, doom);
    endTime = clock();

    deltaTime = endTime -startTime;
    
    //printf("%ld.%03ld\n", deltaTime / 1000, deltaTime % 100);

    return 0;
}

void joseph(int count, int doom) {
    int alive = count; //幸存人数
    int curIndex = 0; //当前人的下标
    int preIndex = count - 1; //前一个人的下标
    int *circle = NULL;

    circle = (int *)malloc(sizeof(int) * count);
    for (int index = 0; index < count; index++) {
        circle[index] = (index + 1) % count; //初始化链表
    }
    while (alive > 0) {
        //只要还有幸存者， 就继续杀
        int num = doom % alive - 1; //直接计算出需要移动的人数
        //直接定位到要出圈的人
        for (int index = 0; index < (num == -1 ? alive - 1 : num); index++) {
            preIndex = curIndex;
            curIndex = circle[curIndex];
        }
        //这个人出圈
        printf("%d ", curIndex + 1);
        alive--;
        //真正的出圈操作
        circle[preIndex] = circle[curIndex];
        //继续处理下一个人
        curIndex = circle[curIndex];
    }
    free(circle);
}
