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
#define MAXN 500000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N,sz[MAXN];
vector<pii> adj[MAXN];
bool done[MAXN];

void Init(int n, int A[], int B[], int D[]) {
	N = n;
	for (int i = 1; i < N; i++) {
		adj[A[i]].push_back({ B[i],D[i] });
		adj[B[i]].push_back({ A[i],D[i] });
	}

}

int dfs(int n,int p) {
	sz[n] = 1;
	for (pii e : adj[n]) {
		if (e.first != p) {
			sz[n] += dfs(e.first, n);
		}
	}
	return sz[n];
}

int getCentroid(int u, int pa, int tot) {
	for (auto e : adj[u])
		if (e.first != pa && !done[e.first] && sz[e.first] * 2 > tot)
			return getCentroid(e.first, u, tot);
	return u;
}

long long Query(int S, int X[], int T, int Y[]) {

}
