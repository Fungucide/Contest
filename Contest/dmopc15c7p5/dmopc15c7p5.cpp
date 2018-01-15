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

int N, h[MAXN], first[MAXN], logtwo[2 * MAXN],Q;
pii table[20][2 * MAXN];
list<int> adj[MAXN];
vector<int> tour, ind[MAXN];

void dfs(int n, int hei) {
	first[n] = tour.size();
	h[n] = hei;
	ind[n].push_back(tour.size());
	tour.push_back(n);
	for (int i : adj[n]) {
		if (first[i] == -1) {
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

int bs(vector<int> val, int num) {//Higher
	int idx, lb = -1, hb = val.size();
	while (hb - lb > 1) {
		idx = (lb + hb) >> 1;
		if (val[idx] > num)
			hb = idx;
		else if (val[idx] < num)
			lb = idx;
		else if (val[idx] == num)
			hb = idx, lb = idx;
	}
	return val[hb];
}

int main() {
	memset(first, -1, sizeof first);
	scan(N);
	int a, b;
	for (int i = 0; i < N;i++) {
		scan(a);
		for (int j = 0;j < a;j++) {
			scan(b);
			adj[i].push_back(--b);
			adj[b].push_back(i);
		}
	}
	dfs(0, 0);
	build(tour.size() - 1);
	scan(Q);
	int lca,cust;
	for (int i = 0; i < Q;i++) {
		scan(a);scan(b);
		if (first[--a] <= first[--b]) {
			printf("%d\n", first[b] - first[a]);
		}else{
			lca = query(a, b).second;
			cust = bs(ind[lca],first[a])-first[a];
			printf("%d\n", first[b] - first[lca] + cust);
		}
	}
	return 0;
}