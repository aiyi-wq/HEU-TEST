/*************************************************************************
	> File Name: 单循环链表.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Thu 03 Dec 2020 01:10:23 PM CST
 ************************************************************************/

typedef struct CircleNode {
    ElemType data;
    struct CircleNode *next;
} CircleNode, *CircleLinkList;

Status InitList_CL(CircleLinkList &L) {
    L = (CircleLinkList)malloc(sizeof(struct CircleNode));
    if (!L) return OVERFLOW;
    L->next = L;
    printf("Success!\n");
    return OK;
}
