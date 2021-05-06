/*************************************************************************
	> File Name: 动态建立学生链表.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Thu 03 Dec 2020 01:04:13 PM CST
 ************************************************************************/

Status Student *create() {
    Student *head;
    Student *p1, *p2;
    n = 0;
    p1 = p2 = (Student *)malloc(LEN);
    scanf("%ld, %f", &p1->num, &p1->score);
    head = NULL;
    while (p1->num != 0) {
        n += 1;
        if (n == 1) {
            head = p1;
        } else {
            p2->next = p1;
        }
        p2 = p1;
        p1 = (Student *)malloc(LEN);
        scanf("%ld, %f", &p1->num, &p1->score);
    }
    p2->next = NULL;
    return head;
}
