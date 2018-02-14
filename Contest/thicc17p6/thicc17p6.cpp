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
#define MAXN 200000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, T;
vector<pii> adj[MAXN];

int dfs(int n, int p) {
	for (pii e : adj[n]) {

	}
}

int main() {
	scan(N); scan(T);
	int a, b, c;
	int total = 0;
	for (int i = 1; i < N; i++) {
		scan(a); scan(b); scan(c);
		adj[--a].push_back({ --b,c });
		adj[b].push_back({ a,c });
		total += c;
	}

	total = total << 1;

	dfs(0, -1);

	return 0;
}