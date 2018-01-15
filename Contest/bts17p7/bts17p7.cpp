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
#define pll pair<long,long>
#define MAXN 100000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, h[MAXN], first[MAXN], logtwo[2 * MAXN], S, par[MAXN];
ll res[MAXN];
pii table[20][2 * MAXN];
list<int> adj[MAXN];
vector<int> tour, ind[MAXN];
priority_queue<pii> q;
pll update[MAXN];//Value,Increment
pll updateU[MAXN];//Value change,Increment Change

pll operator+(const pll &a, const pll &b) {
	return{ a.first + b.first,a.second + b.second };
}

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
	l = first[l];
	r = first[r];
	if (l > r)
		swap(l, r);
	r++;
	int tmp = logtwo[r - l];
	return min(table[tmp][l], table[tmp][r - (1 << tmp)]);
}

int main() {
	memset(first, -1, sizeof first);
	scan(N); scan(S);
	int a, b, c;
	for (int i = 1; i < N; i++) {
		scan(a); scan(b);
		adj[--a].push_back(--b);
		adj[b].push_back(a);
	}
	dfs(0, 0);
	build(tour.size() - 1);
	ll lca, lca2, lca3, leftLength, rightLength, constant;
	for (int i = 0; i < S; i++) {
		scan(a); scan(b); scan(c);
		lca = query(--a, --b).second;
		c--;
		//Check to see if c lies off the path from a->b
		if (h[c] <= h[lca]) {//Above
			constant = h[lca] - h[c];
			leftLength = h[a] - h[lca];
			rightLength = h[b] - h[lca];
			update[a] = update[a] + pll{ constant + leftLength, -1 };
			update[b] = update[b] + pll{ constant + rightLength, -1 };
			updateU[lca] = updateU[lca] + pll{ -constant << 1,2 };
			res[lca] -= constant;
		}
		else if (h[(lca2 = (query(a, c).second))] > h[lca]) {
			constant = h[c] - h[lca2];
			leftLength = h[a] - h[lca2];
			rightLength = h[lca2] + h[b] - (h[lca] << 1);

			update[a] = update[a] + pll{ constant + leftLength,-1 };
			updateU[lca2] = updateU[lca2] + pll{ -constant,1 };
			res[lca2] -= constant;

			update[lca2] = update[lca2] + pll{ constant,1 };
			updateU[lca] = updateU[lca] + pll{ -(constant + h[lca2] - h[lca]) << 1 ,0 };
			update[b] = update[b] + pll{ constant + rightLength,-1 };
			res[lca] -= constant + h[lca2] - h[lca];
		}
		else if (h[(lca3 = (query(b, c).second))] > h[lca]) {
			constant = h[c] - h[lca3];
			leftLength = h[lca3] + h[a] - (h[lca] << 1);
			rightLength = h[b] - h[lca3];

			update[b] = update[b] + pll{ constant + rightLength,-1 };
			updateU[lca3] = updateU[lca3] + pll{ -constant,1 };
			res[lca3] -= constant;

			update[lca3] = update[lca3] + pll{ constant,1 };
			updateU[lca] = updateU[lca] + pll{ -(constant + h[lca3] - h[lca]) << 1,0 };
			update[a] = update[a] + pll{ constant + leftLength,-1 };
			res[lca] -= constant + h[lca3] - h[lca];
		}
		else if (h[lca2] < h[lca]) {
			constant = h[c] + h[lca] - (h[lca2] << 1);
			leftLength = h[a] - h[lca];
			rightLength = h[b] - h[lca];
			update[a] = update[a] + pll{ constant + leftLength, -1 };
			update[b] = update[b] + pll{ constant + rightLength, -1 };
			updateU[lca] = updateU[lca] + pll{ -constant << 1,2 };
			res[lca] -= constant;
		}
		else if (h[lca3] < h[lca]) {
			constant = h[c] + h[lca] - (h[lca3] << 1);
			leftLength = h[a] - h[lca];
			rightLength = h[b] - h[lca];
			update[a] = update[a] + pll{ constant + leftLength, -1 };
			update[b] = update[b] + pll{ constant + rightLength, -1 };
			updateU[lca] = updateU[lca] + pll{ -constant << 1,2 };
			res[lca] -= constant;
		}
		else if (lca2 == lca || lca3 == lca) {
			constant = h[c] - h[lca];
			leftLength = h[a] - h[lca];
			rightLength = h[b] - h[lca];
			update[a] = update[a] + pll{ constant + leftLength, -1 };
			update[b] = update[b] + pll{ constant + rightLength, -1 };
			updateU[lca] = updateU[lca] + pll{ -constant << 1,2 };
			res[lca] -= constant;
		}
		else {
			printf("Here\n");
		}
	}

	int idx = -1;

	while (!q.empty()) {
		idx = q.top().second;
		q.pop();
		res[idx] += update[idx].first;
		update[idx] = update[idx] + updateU[idx];
		update[idx].first += update[idx].second;
		if (idx != 0)
			update[par[idx]] = update[par[idx]] + update[idx];
	}

	for (int i = 0; i < N; i++) {
		printf("%lld ", res[i]);
	}
	return 0;
}