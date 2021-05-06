/*************************************************************************
	> File Name: 八皇后问题.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 14 Sep 2020 11:10:32 AM CST
 ************************************************************************/
#include <cstdio>
#include <cstring>
using namespace std;
// 八皇后问题:  回溯法 
 
int n, tot;
int C[8];
int vis[3][16];
 
void search(int cur)
{
	if(cur == n)
		tot++;
	else
		for(int i = 0; i < n; i++)		// 枚举第cur行第i列 
		{
			//                  次对角线		  主对角线 
			// 验证列        右上到左下的线    左上到右下的线 
			if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n])
			{
				C[cur] = i;		// 第cur个皇后在第i列 
				vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 1;
				search(cur+1);
				vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 0;
			}
		}
}
 
int main()
{
	n = 8;
	tot = 0;
	memset(vis, 0, sizeof(vis));
	search(0);
	printf("sum: %d\n", tot);
	return 0;
}
