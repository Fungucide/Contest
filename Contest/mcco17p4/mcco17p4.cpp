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
#define MAXN 200001//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, M, type[MAXN], before[MAXN][2];
vector<int> adj[MAXN];
queue<int> q[2][2];

inline int f(int t, int iter) {
	int cur;
	if (q[1][iter].empty() && q[0][iter].empty())
		return -1;
	while (!q[t][iter].empty()) {
		cur = q[t][iter].front();
		q[t][iter].pop();
		for (int i : adj[cur])
			if (--before[i][iter] == 0)
				q[type[i]][iter].push(i);
	}
	return 1 + f(t ? 0 : 1, iter);
}

int main() {
	scan(N); scan(M);
	for (int i = 0; i < N; i++) {
		scan(type[i]);
	}
	int a, b;
	for (int i = 0; i < M; i++) {
		scan(a); scan(b);
		adj[a].push_back(b);
		before[b][0]++;
		before[b][1]++;
	}
	for (int i = 0; i < N; i++) {
		if (before[i][0] == 0) {
			q[type[i]][0].push(i);
			q[type[i]][1].push(i);
		}
	}
	printf("%d\n", min(f(0, 0), f(1, 1)));
	return 0;
}