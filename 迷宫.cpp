/*************************************************************************
	> File Name: 迷宫.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 20 Oct 2020 07:46:38 AM CST
 ************************************************************************/
#include <iostream>
#include <cstring>

using namespace std;

int g[6][6];
bool used[6][6];
int sx = 0, sy = 0, ex = 4, ey = 4;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
struct Point {
    int x, y;
    int steps;
    int p[30];
} que[30], v, u, s;

void bfs() {
    s.x = sx;
    s.y = sy;
    s.steps = 0;
    s.p[s.steps] = 0;
    int f = 0, e = 0;
    que[e++] = s;
    used[sx][sy] = true;
    while (f <= e) {
        u = que[f++];
        if (u.x == ex && u.y == ey) {
            int xx = 0, yy = 0;
            cout << "(" << xx << ", " << yy << ")" << endl;
            for (int i = 1; i <= u.steps; ++i) {
                xx = xx + dx[u.p[i]];
                yy = yy + dy[u.p[i]];
                cout << "(" << xx << ", " << yy << ")" << endl;
            }
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = u.x + dx[i];
            int ny = u.y + dy[i];
            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && g[nx][ny] != 1 && !used[nx][ny]) {
                v.x = nx;
                v.y = ny;
                v.steps = u.steps + 1;
                for (int j = 0; j < u.steps; ++j) {
                    v.p[j] = u.p[j];
                }
                v.p[v.steps] = i;
                que[e++] = v;
                used[nx][ny] = true;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> g[i][j];
        }
    }
    memset(used, false, sizeof(used));
    bfs();
    return 0;
}
