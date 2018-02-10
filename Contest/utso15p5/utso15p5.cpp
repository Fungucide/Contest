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
#define MAXN 100000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

struct edge {
	int a, b, w;
	bool operator<(const edge& rhs) const { return w < rhs.w; }
};

int N, M, cnt = 0, ind = 0, top[MAXN], chain[MAXN], par[MAXN], sub[MAXN], dep[MAXN], pos[MAXN], seg[2 * MAXN], disjoint[MAXN];
vector<pii> adj[MAXN];
vector<edge> E, notUsed;

void constructD() {
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

void update(int p, int value) {
	for (seg[p += N] = value; p > 1; p >>= 1)
		seg[p >> 1] = max(seg[p], seg[p ^ 1]);
}

int query(int l, int r) {
	int res;
	bool flag = false;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1)
			(res = flag ? max(res, seg[l]) : seg[l]), l++, flag = true;
		if (r & 1)
			r--, (res = flag ? max(res, seg[r]) : seg[r]), flag = true;
	}
	return res;
}

int dfs(int n, int prev = -1, int d = 0) {
	par[n] = prev;
	sub[n] = 1;
	dep[n] = d;
	for (pii i : adj[n])
		if (i.first != prev)
			sub[n] += dfs(i.first, n, d + 1);
	return sub[n];
}

void hld(int n, int prev = -1, int cost = -1) {
	if (top[cnt] == -1)
		top[cnt] = n;
	chain[n] = cnt;
	pos[n] = ind;
	seg[N+ind++] = cost;
	int idx = -1;
	for (pii i : adj[n])
		if (i.first != prev && (idx == -1 || sub[i.first] > sub[idx]))
			idx = i.first, cost = i.second;
	if (idx == -1)
		return;
	hld(idx, n, cost);
	for (pii i : adj[n]) {
		if (i.first != prev && i.first != idx) {
			++cnt;
			hld(i.first, n, i.second);
		}
	}
}

int query_up(int u, int v) {
	int res = -1;
	while (chain[u] != chain[v]) {
		if (dep[top[chain[u]]] < dep[top[chain[v]]])
			swap(u, v);
		res = max(res, query(pos[top[chain[u]]], pos[u]));
		u = par[top[chain[u]]];
	}
	if (pos[u] > pos[v])
		swap(u, v);
	return max(res, query(pos[u] + 1, pos[v]));
}

void update_tree(int u, int v, int val) {
	if (dep[u] < dep[v])
		swap(u, v);
	update(pos[u], v);
}

void construct() {
	dfs(0);
	hld(0);
	for (int i = N - 1; i > 0; --i)
		seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
}

int main() {
	memset(top, -1, sizeof top);
	scan(N); scan(M);
	constructD();
	int a, b, c;
	for (int i = 0; i < M; i++) {
		scan(a); scan(b); scan(c);
		E.push_back({ --a,--b,c });
	}
	sort(E.begin(), E.end());
	int totalW = 0;
	int nEdge = 0;
	for (edge e : E) {
		if (!cmp(e.a, e.b)) {
			merge(e.a, e.b);
			adj[e.a].push_back({ e.b,e.w });
			adj[e.b].push_back({ e.a,e.w });
			totalW += e.w;
			nEdge++;
		}
		else
			notUsed.push_back(e);
	}
	if (nEdge != N - 1) {
		printf("-1\n");
		return 0;
	}
	construct();
	int res = 1 << 30, temp;
	for (edge e : notUsed) {
		temp = query_up(e.a, e.b);
		if (temp < e.w)
			res = min(res, totalW + e.w - temp);
	}
	if (res == totalW || res == 1 << 30)
		printf("-1\n");
	else
		printf("%d\n", res);
	return 0;
}