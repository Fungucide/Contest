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
#define _CRT_SECURE_NO_WARNINGS

#endif

#define pii pair<int,int>
#define MAXN 100000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

struct edge {
	int a, b, w, c;
};

int N, M, S, E, len[MAXN], rev[MAXN];
vector<edge> adj[MAXN], radj[MAXN];
priority_queue<pii> pq;


int main() {
	memset(len, -1, sizeof len);
	memset(rev, -1, sizeof rev);
	scan(N); scan(M); scan(S); scan(E);
	int a, b, c, d;
	for (int i = 0; i < M; i++) {
		scan(a); scan(b); scan(c); scan(d);
		adj[--a].push_back({ --b,c,d });
		radj[b].push_back({ a,c,d });
	}
	scan(S); scan(E);
	--S; --E;
	len[S] = 0;
	pq.push({ 0,S });
	while (!pq.empty()) {
		pii p = pq.top();
		pq.pop();
		for (edge e : adj[p.second])
			if (len[e.b] == -1 || len[e.b]>p.first + e.w) {
				len[e.b] = p.first + e.w;
				pq.push({ len[e.b],e.b });
			}
	}

	rev[E] = 0;
	pq.push({0,E});
	while (!pq.empty()) {
		pii p = pq.top();
		pq.pop();
		for (edge e : radj[p.second])
			if (rev[e.b] == -1 || rev[e.b]>p.first + e.w) {
				rev[e.b] = p.first + e.w;
				pq.push({ rev[e.b],e.b });
			}
	}
	return 0;
}