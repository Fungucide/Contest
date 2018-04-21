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
#define MAXN 100001//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N,M,K,art[MAXN],disFrom[MAXN],disBack[MAXN];
vector<int> adj[MAXN],rAdj[MAXN];

int main() {
	scan(N); scan(M);
	int a, b;
	for (int i = 0; i < M; i++) {
		scan(a); scan(b);
		adj[--a].push_back(--b);
		rAdj[b].push_back(a);
	}
	scan(K);
	for (int i = 0; i < K; i++) {
		scan(art[i]);
		art[i]--;
	}
	memset(disFrom, -1, sizeof disFrom);
	memset(disBack, -1, sizeof disBack);
	queue<int> q;
	q.push(0);
	disFrom[0] = 0;
	disBack[0] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i : adj[cur]) {
			if (disFrom[i] != -1)
				continue;
			disFrom[i] = disFrom[cur] + 1;
			q.push(i);
		}
	}
	q.push(0);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i : rAdj[cur]) {
			if (disBack[i] != -1)
				continue;
			disBack[i] = disBack[cur] + 1;
			q.push(i);
		}
	}
	int res = 0;
	for (int i = 0; i < K; i++) {
		if (disFrom[art[i]] == -1 || disBack[art[i]] == -1) {
			printf("-1\n");
			return 0;
		}
		res += disFrom[art[i]];
		res += disBack[art[i]];
	}
	printf("%d\n", res);
	return 0;
}