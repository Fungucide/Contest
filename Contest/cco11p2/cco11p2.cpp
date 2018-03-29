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

#define INT_INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define MAXN 1601//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

struct edge {
	int d, w, a;
	bool operator<(const edge &a)const {
		return w > a.w;
	}
};

int S, N, E;
vector<edge> adj[MAXN];
priority_queue<edge> pq;
bool v[MAXN];
int d[MAXN];


int main() {
	memset(d, 0x3f, sizeof d);
	scan(S); scan(N); scan(E);
	int a, b, c, d;
	for (int i = 0; i < E; i++) {
		scan(a); scan(b); scan(c); scan(d);
		adj[a].push_back({ b,c,d });
		adj[b].push_back({ a,c,d });
	}

	pq.push({ 0,0,0 });

	while (!pq.empty()) {
		edge n = pq.top();
		pq.pop();
		//v[n.d] = true;
		for (edge e : adj[n.d]) {
			if (v[e.d])
				continue;
			else if (!e.a || n.a +	e.w <= S) {
				pq.push({ e.d, n.w + e.w, e.a ? n.a + e.w : n.a });
			}
		}
	}
	if (!v[N - 1])
		printf("-1\n");
	else
		printf("%d\n", min);

	return 0;
}