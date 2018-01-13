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

int N, h[MAXN], first[MAXN], logtwo[2 * MAXN];
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
	int tmp = logtwo[r - l];
	return min(table[tmp][l], table[tmp][r - (1 << tmp)]);
}

int main() {
	scan(N);
	return 0;
}