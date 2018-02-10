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

int N,cnt = 0, ind = 0, top[MAXN], chain[MAXN], par[MAXN], special[MAXN], dep[MAXN], pos[MAXN],seg[2*MAXN];
vector<pii> adj[MAXN];

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
	int sub = 1;
	par[n] = prev;
	dep[n] = d;
	int m = -1;
	for (pii i : adj[n]) {
		if (i.first != prev) {
			int sz = dfs(i.first, n, d + 1);
			sub += sz;
			if (sz > m)
				special[n] = i.first, m = sz;
		}
	}
	return sub;
}

void hld(int n, int prev = -1, int cost = -1) {
	if (top[cnt] == -1)
		top[cnt] = n;
	chain[n] = cnt;
	pos[n] = ind;
	seg[N + ind++] = cost;
	if (special[n] == -1)
		return;
	hld(special[n], n, cost);
	for (pii i : adj[n]) {
		if (i.first != prev && i.first != special[n]) {
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
	memset(special, -1, sizeof special);
	memset(top, -1, sizeof top);
	scan(N);
	return 0;
}