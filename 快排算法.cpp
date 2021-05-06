/*************************************************************************
	> File Name: 快排算法.cpp
	> Author: Aiiii
	> Mail: 2646967818@qq.com
	> Created Time: Thu 03 Dec 2020 01:16:18 PM CST
 ************************************************************************/
int Partition(SqList &L, int low, int high) {
    L.r[0] = L.r[low];
    pivotkey = L.r[low].key;
    while (low < high) {
        while (low < high && L.r[high].key >= pivotkey) --high;
        L.r[low] = L.r[high];
        while (low < high && L.r[low].key <= pivotkey) ++low;
        L.r[high] = L.r[Low];
    }
    L.r[low] = L.r[0];
    return low;
 }
