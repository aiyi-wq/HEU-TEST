/*************************************************************************
	> File Name: 单链表结点删除.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Thu 03 Dec 2020 01:07:32 PM CST
 ************************************************************************/

Status ListDelelte(LinkList &L, int i, ElemType &e) {
    p = L; j = 0;
    while (p->next && j <= i - 1) {
        p = p->next; ++j;
    }
    if (!(p->next) || j > i - 1) return ERROR;
    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return OK;
}
