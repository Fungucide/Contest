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
#define MAXN 10000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, h[MAXN], first[MAXN], log_two[2 * MAXN];
pii table[20][2 * MAXN];
list<int> adj[MAXN];
vector<int> tour, ind[MAXN];//ind for where it's been

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

void build(int n) {
	for (int i = 0; i < n; ++i)
		table[0][i] = { h[tour[i]],tour[i] }, log_two[i] = (i >> (log_two[i - 1] + 1)) ? log_two[i - 1] + 1 : log_two[i - 1];;
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
	int tmp = log_two[r - l];
	return min(table[tmp][l], table[tmp][r - (1 << tmp)]);
}

int main() {
	memset(first, -1, sizeof first);
	scan(N);
	dfs(0, 0);
	build(tour.size() - 1);
	return 0;
}