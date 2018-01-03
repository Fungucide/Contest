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

#endif

#define MAXN 2002
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

struct edge {
	int n, t, h;
	bool operator<(const edge& s) const {
		return t > s.t;
	}
};

int N, M, K, dis[MAXN][202], start, des;
vector<edge> adj[MAXN];
priority_queue<edge> pq;

int main() {
	memset(dis, -1, sizeof dis);
	scan(K);scan(N);scan(M);
	int a, b, c, d;
	for (int i = 0;i < M;i++) {
		scan(a);scan(b);scan(c);scan(d);
		adj[a].push_back({ b,c,d });
		adj[b].push_back({ a,c,d });
	}
	scan(start);scan(des);
	dis[start][0] = 0;
	pq.push({ start,0,0 });

	while (!pq.empty()) {
		edge e = pq.top();
		pq.pop();
		for (edge con : adj[e.n]) {
			if (e.h + con.h < K && dis[con.n][e.h + con.h] == -1 || dis[con.n][e.h + con.h]>e.t + con.t) {
				dis[con.n][e.h + con.h] = e.t + con.t;
				pq.push({ con.n,e.t + con.t ,e.h + con.h });
			}
		}
	}
	int res = -1;
	for (int i = 0;i < 202;i++) {
		if (res == -1 || (dis[des][i] != -1 && dis[des][i] < res)) {
			res = dis[des][i];
		}
	}
	printf("%d\n", res);
	return 0;
}