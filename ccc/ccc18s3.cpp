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
#include <list>
#include <stack>
#include <set>
#define scanf scanf_s

#endif

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define MAXN 105

using namespace std;

struct cust {
	int w, x, y;
	bool operator<(const cust &a)const {
		return w > a.w;
	}
};

int N, M, dis[MAXN][MAXN], x, y;
pii act[4] = { pii{0,1}, pii{1,0} ,pii{0,-1},pii{-1,0} };
char dir[MAXN][MAXN];// B blocked, U up, D down, L left, R right
priority_queue<cust> pq;
vector<pii> nothing, wall;

int main() {
	memset(dis, -1, sizeof dis);
	scanf("%d%d", &N, &M);
	char c;
	c = getchar();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			c = getchar();
			if (c == 'S') {
				x = j, y = i;
			}
			else if (c == 'W') {
				dir[j][i] = 'W';
			}
			else if (c == 'L' || c == 'R' || c == 'U' || c == 'D') {
				dir[j][i] = c;
			}
			else if (c == 'C') {
				wall.push_back({ j,i });
			}
			if (c == '.')
				nothing.push_back({ j,i });
		}
		c = getchar();
	}

	for (pii w : wall) {
		int j = w.first;
		int i = w.second;
		for (int k = i; k < N; k++) {
			if (dir[j][k] == 'W')
				break;
			if (dir[j][k] != 'L' &&  dir[j][k] != 'R' &&  dir[j][k] != 'U' &&  dir[j][k] != 'D')
				dir[j][k] = 'B';
		}
		for (int k = i; k >= 0; k--) {
			if (dir[j][k] == 'W')
				break;
			if (dir[j][k] != 'L' &&  dir[j][k] != 'R' &&  dir[j][k] != 'U' &&  dir[j][k] != 'D')
				dir[j][k] = 'B';
		}

		for (int k = j; k < M; k++) {
			if (dir[k][i] == 'W')
				break;
			if (dir[k][i] != 'L' &&  dir[k][i] != 'R' &&  dir[k][i] != 'U' &&  dir[k][i] != 'D')
				dir[k][i] = 'B';
		}
		for (int k = j; k >= 0; k--) {
			if (dir[k][i] == 'W')
				break;
			if (dir[k][i] != 'L' &&  dir[k][i] != 'R' &&  dir[k][i] != 'U' &&  dir[k][i] != 'D')
				dir[k][i] = 'B';
		}
	}

	if (dir[x][y] != 'B') {
		dis[x][y] = 0;
		pq.push({ 0,x,y });
	}
	while (!pq.empty()) {
		cust cur = pq.top();
		pq.pop();
		if (dir[cur.x][cur.y] == 'U') {
			pii a = act[2];
			int nx = cur.x + a.first, ny = cur.y + a.second;
			if (dir[nx][ny] == 'B' || dir[nx][ny] == 'W')
				continue;
			if (dis[nx][ny] > cur.w || dis[nx][ny] == -1) {
				dis[nx][ny] = cur.w;
				pq.push({ dis[nx][ny],nx,ny });
			}
			continue;
		}
		else if (dir[cur.x][cur.y] == 'D') {
			pii a = act[0];
			int nx = cur.x + a.first, ny = cur.y + a.second;
			if (dir[nx][ny] == 'B' || dir[nx][ny] == 'W')
				continue;
			if (dis[nx][ny] > cur.w || dis[nx][ny] == -1) {
				dis[nx][ny] = cur.w;
				pq.push({ dis[nx][ny],nx,ny });
			}
			continue;
		}
		else if (dir[cur.x][cur.y] == 'L') {
			pii a = act[3];
			int nx = cur.x + a.first, ny = cur.y + a.second;
			if (dir[nx][ny] == 'B' || dir[nx][ny] == 'W')
				continue;
			if (dis[nx][ny] > cur.w || dis[nx][ny] == -1) {
				dis[nx][ny] = cur.w;
				pq.push({ dis[nx][ny],nx,ny });
			}
			continue;
		}
		else if (dir[cur.x][cur.y] == 'R') {
			pii a = act[1];
			int nx = cur.x + a.first, ny = cur.y + a.second;
			if (dir[nx][ny] == 'B' || dir[nx][ny] == 'W')
				continue;
			if (dis[nx][ny] > cur.w || dis[nx][ny] == -1) {
				dis[nx][ny] = cur.w;
				pq.push({ dis[nx][ny],nx,ny });
			}
			continue;
		}
		//Assuming empty
		for (pii a : act) {
			int nx = cur.x + a.first, ny = cur.y + a.second;
			if (dir[nx][ny] == 'B' || dir[nx][ny] == 'W')
				continue;
			if (dis[nx][ny] > cur.w + 1 || dis[nx][ny] == -1) {
				dis[nx][ny] = cur.w + 1;
				pq.push({ dis[nx][ny],nx,ny });
			}
		}
	}

	for (pii loc : nothing) {
		printf("%d\n", dis[loc.first][loc.second]);
	}

	return 0;
}