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
#define MAXN 1000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

struct trip {
	int dis, lTim, n;

	bool operator<(const trip &a)const {
		return dis > a.dis;
	}

};

int N, M, L, T, dis[MAXN][102];
vector<pii> adj[MAXN];
bool hasTim[MAXN];
priority_queue<trip> q;

int main() {
	memset(dis, -1, sizeof dis);
	scan(N); scan(M); scan(L); scan(T);
	int a, b, c;
	for (int i = 0; i < N; i++) {
		scan(a);
		hasTim[i] = a;
	}

	for (int i = 0; i < M; i++) {
		scan(a); scan(b); scan(c);
		adj[--a].push_back({ --b,c });
		adj[b].push_back({ a,c });
	}
	q.push({ 0,0,0 });
	trip t;
	while (!q.empty()) {
		t = q.top();
		q.pop();
		for (pii e : adj[t.n]) {
			if ((dis[e.first][e.second] == -1 || dis[e.first][e.second] > t.dis + e.second + T) && hasTim[t.n]) {
				dis[e.first][e.second] = t.dis + e.second + T;
				q.push({ t.dis + e.second + T,e.second,e.first });
			}
			if (t.lTim + e.second <= L)
				if (dis[e.first][t.lTim + e.second] == -1 || dis[e.first][t.lTim + e.second] > t.dis + e.second) {
					dis[e.first][t.lTim + e.second] = t.dis + e.second;
					q.push({ t.dis + e.second,t.lTim + e.second,e.first });
				}
		}
	}
	int small = -1;
	for (int i = 0; i <= L; i++) {
		if (small == -1) {
			small = dis[N - 1][i];
		}
		else if (dis[N - 1][i] != -1)
			small = min(small, dis[N - 1][i]);
	}
	printf("%d\n", small);
	return 0;
}