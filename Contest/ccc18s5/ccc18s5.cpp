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
#define MAXN 100005

using namespace std;

struct edge {
	ll type, a, b, w;
	bool operator<(const edge& rhs) const { if (w != rhs.w) { return w < rhs.w; } else { return a > rhs.a; } }
};

ll N, M, P, Q;
int disjoint[MAXN][2];
vector<edge> edges;

void construct() {
	for (int i = 0; i < M; i++)
		disjoint[i][0] = i;
	for (int i = 0; i < N; i++)
		disjoint[i][1] = i;
}

int find(int x, int type) {
	if (disjoint[x][type] == x)
		return x;
	return disjoint[x][type] = find(disjoint[x][type], type);
}

bool cmp(int x, int y, int type) {
	return find(x, type) == find(y, type);
}

bool merge(int x, int y, int type) {
	disjoint[find(y, type)][type] = find(x, type);
	return true;
}

int main() {
	scanf("%lld%lld%lld%lld", &N, &M, &P, &Q);
	construct();
	ll a, b, c;
	ll totalCost = 0;
	for (int i = 0; i < P; i++) {
		scanf("%lld%lld%lld", &a, &b, &c);
		--a; --b;
		edges.push_back(edge{ 0,a,b,c });//Horizontal Edges 0 P
		totalCost += c * N;
	}

	for (int i = 0; i < Q; i++) {
		scanf("%lld%lld%lld", &a, &b, &c);
		--a; --b;
		edges.push_back(edge{ 1,a,b,c });//Vertical Edges 1 Q
		totalCost += c * M;
	}

	sort(edges.begin(), edges.end());

	ll cost = 0, nEdges = N * M - 1, hEdges = N, vEdges = M, amount;

	for (edge e : edges) {
		if (!cmp(e.a, e.b, e.type)) {
			merge(e.a, e.b, e.type);
			amount = e.type ? vEdges : hEdges;
			nEdges -= amount;
			cost += amount * e.w;
			e.type ? hEdges-- : vEdges--;
			if (nEdges == 0)
				break;
		}
	}
	if (nEdges == 0)
		printf("%lld\n", totalCost - cost);
	else
		printf("0\n");
	return 0;
}