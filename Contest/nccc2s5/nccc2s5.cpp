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
#define MAXN 1000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

struct edge {
	int a, b, w;

	bool operator<(const edge &a)const {
		return w < a.w;
	}
};

int N, M, Q, disjoint[MAXN];
bool update = true, v[MAXN];
priority_queue<edge> pq;
vector<edge> adj;
vector<pii> mst[MAXN];

void construct() {
	for (int i = 0; i < N; i++)
		disjoint[i] = i;
}

int find(int x) {
	if (disjoint[x] == x)
		return x;
	return disjoint[x] = find(disjoint[x]);
}

bool cmp(int x, int y) {
	return find(x) == find(y);
}

void merge(int x, int y) {
	disjoint[find(y)] = find(x);
}

void cust() {
	for (vector<pii> v : mst)
		v.clear();
	for (edge e : adj)
		pq.push(e);
	int nEdges = N - 1;
	construct();
	while (pq.empty()) {
		edge e = pq.top();
		pq.pop();
		if (!cmp(e.a, e.b)) {
			merge(e.a, e.b);
			mst[e.a].push_back({ e.b,e.w });
			mst[e.b].push_back({ e.a,e.w });
			nEdges--;
		}
	}
	update = false;
}

bool dfs(int s, int e, int w) {
	bool res = false;
	for (pii p : mst[s]) {
		if (!v[p.first] && p.second >= w) {
			if (p.first == e)
				return true;
			else {
				res = dfs(p.first, e, w);
				if (res)
					break;
			}
		}
	}
	v[s] = true;
	return res;
}

int main() {
	scan(N); scan(M);
	int a, b, c, d;
	for (int i = 0; i < M; i++) {
		scan(a); scan(b); scan(c);
		adj.push_back({ --a,--b,c });
		update = true;
	}
	scan(Q);
	for (int i = 0; i < Q; i++) {
		scan(a); scan(b); scan(c);
		--b;
		if (a == 1) {
			adj[b].w = c;
		}
		else {
			scan(d);
			--c;
			if (update)
				cust();
			memset(v, 0, sizeof v);
			printf("%d\n", dfs(b, c, d) ? 1 : 0);
		}
	}
	return 0;
}