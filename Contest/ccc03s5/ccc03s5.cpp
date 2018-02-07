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

int C, R, D, weight[MAXN];
vector<pii> adj[MAXN];
priority_queue<pii> pq;

int main() {
	scan(C); scan(R); scan(D);
	int a, b, c;
	for (int i = 0; i < R; i++) {
		scan(a); scan(b); scan(c);
		adj[--a].push_back({ --b,c });
		adj[b].push_back({ a,c });
	}
	weight[0] = 1<<30;
	pq.push({ 1 << 30,0 });
	while (!pq.empty()) {
		pii n = pq.top();
		pq.pop();
		for (pii e : adj[n.second]) {
			int minW = min(e.second, n.first);
			if (minW > weight[e.first]) {
				weight[e.first] = minW;
				pq.push({ minW,e.first });
			}
		}
	}
	int res = 1 << 30;
	for (int i = 0; i < D; i++) {
		scan(a);
		res = min(res, weight[--a]);
	}
	printf("%d\n", res);
	return 0;
}