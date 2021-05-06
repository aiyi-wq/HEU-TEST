/*************************************************************************
	> File Name: 合并顺序表.c
	> Author: 
	> Mail: 
	> Created Time: Mon 12 Oct 2020 05:17:15 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100  //线性表存储空间的初始分配量

typedef struct {
    int *elem;
    int length, listsize;
} Sqlist;

Sqlist *Init_Sqlist();
void Insert_Sq(Sqlist *);
void Output_Sq(Sqlist *);
void Merge_Sq(Sqlist *, Sqlist *, Sqlist *);
int Check_Sq(Sqlist *);

int main() {
    Sqlist *ListA = Init_Sqlist(), *ListB = Init_Sqlist();
    Sqlist *ListC = Init_Sqlist();
    printf("创建有序表A\n");
    Insert_Sq(ListA);
    int aflag = Check_Sq(ListA);
    if (aflag) {
        printf("该序列不是递增序列，请重新输入!\n");
        Init_Sqlist(ListA);
        aflag = Check_Sq(ListA);
    }
    printf("创建成功!\n");

    printf("创建有序表B\n");
    Insert_Sq(ListB);
    int bflag = Check_Sq(ListB);
    if (bflag) {
        printf("该序列不是递增序列，请重新输入!\n");
        Init_Sqlist(ListB);
        bflag = Check_Sq(ListB);
    }
    printf("创建成功!\n");

    printf("A表元素如下：\n");
    Output_Sq(ListA);
    printf("B表元素如下：\n");
    Output_Sq(ListB);

    Merge_Sq(ListA, ListB, ListC);
    printf("合并后的C表如下:  \n");
    Output_Sq(ListC);
    return 0;
}

//初始化线性表
Sqlist *Init_Sqlist() {
    Sqlist *List = (Sqlist *)malloc(sizeof(Sqlist));
    List->elem = (int *)malloc(sizeof(int) * MAXSIZE);
    List->length = 0;
    List->listsize = MAXSIZE;
    return List;
}

//往网顺序表中插入元素
void Insert_Sq(Sqlist *List) {
    int n;
    printf("请输入这个有序表的元素个数: \n");
    scanf("%d", &n);
    List->length = n;
    printf("请依次输入这%d个数：\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &List->elem[i]);
    }
    return ;
}

//输出有序表
void Output_Sq(Sqlist *List) {
    for (int i = 0; i < List->length; ++i) {
        i == 0 && printf("%d", List->elem[i]);
        i != 0 && printf(" %d", List->elem[i]);
    }
    printf("\n");
}

//合并两个递增顺序表合并成一个单调递减的顺序表
void Merge_Sq(Sqlist *Lista, Sqlist *Listb, Sqlist *Listc) {
    Init_Sqlist(Listc);
    Listc->length = Lista->length + Listb->length;
    //找出两个表的未位置并定义表C新元素的开始
    int i = Lista->length - 1, j = Listb->length - 1;
    int k = 0;
    while (i >= 0 && j >= 0) {
        if (Lista->elem[i] >= Listb->elem[j]) {
            Listc->elem[k++] = Lista->elem[i--];
        } else {
            Listc->elem[k++] = Listb->elem[j--];
        }
    }
    //如果表A中还有元素，依次赋值给表C
    while (i >= 0) {
        Listc->elem[k++] = Lista->elem[i--];
    }
    //如果表B中还有元素，依次赋值给表C
    while (j >= 0) {
        Listc->elem[k++] = Listb->elem[j--];
    }
    return ;
}

int Check_Sq(Sqlist *List) {
    int flag = 0;
    for (int i = 1; i < List->length; ++i) {
        if (List->elem[i] < List->elem[i - 1]) flag = 1;
    }
    return flag;
}
