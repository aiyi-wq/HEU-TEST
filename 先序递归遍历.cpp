/*************************************************************************
	> File Name: 先序递归遍历.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Thu 03 Dec 2020 01:13:13 PM CST
 ************************************************************************/

Status PreOrderTraverse(BTree T, Status(* Visit)(TElemType)) {
    if (T) {
        if (Visit(T->data)) {
            if (PreOrderTraverse(T->lchild, Visit)) {
                if (PreOrderTraverse(T->rchild, Visit)) {
                    return OK;
                }
            }
        } return ERROR;
    } else {
        return OK;
    }
}
