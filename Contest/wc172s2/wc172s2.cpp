#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#define scanf scanf_s

#endif

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define MAXN 1502//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

struct cust {
	int w, x, y;
	bool operator<(const cust &a)const {
		return w > a.w;
	}
};

int R, C, sx, sy, ex, ey, dis[MAXN][MAXN];
pii act[4] = { pii{ 0,1 }, pii{ 1,0 } ,pii{ 0,-1 },pii{ -1,0 } };
bool block[MAXN][MAXN], canMove[MAXN][MAXN][4];
priority_queue<cust> pq;

int main() {
	memset(dis, -1, sizeof dis);
	scan(R); scan(C);
	char c;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			c = getchar();
			if (c == 'S')
				sx = i, sy = j;
			else if (c == 'D')
				ex = i, ey = j;
			else if (c == '*') {
				block[i][j] = true;
			}
		}
		getchar();
	}
	int count = 0;
	for (int i = 0; i <= R; i++) {
		count = 0;
		for (int j = 0; j < C; j++) {
			if (!block[i][j])
				canMove[i][j][2] =true;
			else
				count++;
			if (count >= 2)
				break;
		}
		count = 0;
		for (int j = C-1; j >=0; j--) {
			if (!block[i][j])
				canMove[i][j][0] = true;
			else
				count++;
			if (count >= 2)
				break;
		}
	}
	for (int j = 0; j < C; j++) {
		count = 0;
		for (int i = 0; i < R; i++) {
			if (!block[i][j])
				canMove[i][j][3] = true;
			else
				count++;
			if (count >= 2)
				break;
		}
		count = 0;
		for (int i = R - 1; i >= 0; i--) {
			if (!block[i][j])
				canMove[i][j][1] = true;
			else
				count++;
			if (count >= 2)
				break;
		}
	}

	dis[sx][sy] = 0;
	pq.push({ 0,sx,sy });
	while (!pq.empty()) {
		cust cur = pq.top();
		pq.pop();
		int nx, ny;
		for (int i = 0; i < 4;i++) {
			nx = cur.x + act[i].first;
			ny = cur.y + act[i].second;
			if (block[nx][ny] || nx == -1 || ny == -1 || nx >= R || ny >= C)
				continue;
			if (!canMove[cur.x][cur.y][i])
				continue;
			if (dis[nx][ny] == -1 || dis[nx][ny] > cur.w + 1) {
				dis[nx][ny] = cur.w + 1;
				pq.push({ dis[nx][ny],nx,ny });
			}
		}
	}
	printf("%d\n", dis[ex][ey]);
	return 0;
}