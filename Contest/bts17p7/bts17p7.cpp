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

struct update {
	ll val;
	int height;
	ll change;

	bool operator<(const update& a)const {
		return height < a.height;
	}
};

int N, h[MAXN], first[MAXN], logtwo[2 * MAXN], S, par[MAXN];
ll res[MAXN];
pii table[20][2 * MAXN];
list<int> adj[MAXN];
vector<int> tour, ind[MAXN];
priority_queue<update> u[MAXN];
priority_queue<pii> q;

void dfs(int n, int hei) {
	first[n] = tour.size();
	q.push({ hei,n });
	h[n] = hei;
	ind[n].push_back(tour.size());
	tour.push_back(n);
	for (int i : adj[n]) {
		if (first[i] == -1) {
			par[i] = n;
			dfs(i, hei + 1);
			ind[n].push_back(tour.size());
			tour.push_back(n);
		}
	}
}

int count_bits(int n) {
	int cnt = 0;
	while (n = (n >> 1))
		++cnt;
	return cnt;
}

void build(int n) {
	for (int i = 0; i < n; ++i)
		table[0][i] = { h[tour[i]],tour[i] }, logtwo[i] = count_bits(i);
	for (int i = 1, curr = 2; curr < n; curr <<= 1, ++i)
		for (int j = 0; j + curr <= n; ++j)
			table[i][j] = min(table[i - 1][j], table[i - 1][j + (curr >> 1)]);
}

pii query(int l, int r) {
	if (l > r)
		swap(l, r);
	int tmp = logtwo[r - l];
	return min(table[tmp][l], table[tmp][r - (1 << tmp)]);
}

int main() {
	memset(first, -1, sizeof first);
	scan(N);scan(S);
	int a, b, c;
	for (int i = 1;i < N;i++) {
		scan(a);scan(b);
		adj[--a].push_back(--b);
		adj[b].push_back(a);
	}
	dfs(0, 0);
	build(tour.size() - 1);
	int lca, lca2, leftLength, rightLength, constant;
	for (int i = 0; i < S;i++) {
		scan(a);scan(b);scan(c);
		lca = query(first[--a], first[--b]).second;
		c--;
		//Check to see if c lies off the path from a->b
		if (h[c] <= h[lca]) {//Above
			constant = h[lca] - h[c];
			leftLength = h[a] - h[lca];
			rightLength = h[b] - h[lca];
			u[a].push({ constant + leftLength,h[lca],-1 });
			u[b].push({ constant + rightLength,h[lca],-1 });
			res[lca] -= constant;
		}
		else if (h[(lca2 = (query(first[a], first[c]).second))] < h[lca]) {
			constant = h[c] - h[lca2];
			leftLength = h[a] - h[lca2];
			rightLength = h[lca2] + h[b] - (h[lca] << 1);
			u[a].push({ constant + leftLength,h[lca2],-1 });
			res[lca2] -= constant;
			u[lca2].push({ constant,h[lca],1 });
			u[b].push({ constant + rightLength,h[lca],-1 });
			res[lca] -= constant + h[lca2] - h[lca];
		}
		else if (h[(lca2 = (query(first[b], first[c]).second))] < h[lca]) {
			constant = h[c] - h[lca2];
			leftLength = h[lca2] + h[a] - (h[lca] << 1);
			rightLength = h[b] - h[lca2];
			u[lca2].push({ constant,h[lca],1 });
			u[a].push({ constant + leftLength,h[lca],-1 });
			res[lca] -= constant + h[lca2] - h[lca];
			u[b].push({ constant + rightLength,h[lca2],-1 });
			res[lca2] -= constant;
		}
		else if (h[lca2] == h[lca]) {
			constant = h[lca2] - h[lca];
			leftLength = h[a] - h[lca];
			rightLength = h[b] - h[lca];
			u[a].push({ constant + leftLength,h[lca],-1 });
			u[b].push({ constant + rightLength,h[lca],-1 });
			res[lca] -= constant;
		}
	}

	int idx;
	update up;

	while (!q.empty()) {
		idx = q.top().second;
		q.pop();
		while (!u[idx].empty()) {
			up = u[idx].top();
			u[idx].pop();
			res[idx] += up.val;
			if (h[idx] != up.height) {
				up.val += up.change;
				u[par[idx]].push(up);
			}
		}
	}

	for (int i = 0;i < N;i++) {
		printf("%lld ", res[i]);
	}
	return 0;
}