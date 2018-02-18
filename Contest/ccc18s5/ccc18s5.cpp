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

int N, M, P, Q, disjoint[MAXN][2];

vector<edge> edges;

struct edge {
	ll type, a, b, w;
	bool operator<(const edge& rhs) const { if (w != rhs.w) { return w < rhs.w; } else { return a > rhs.a; } }
};

void construct() {
	for (int i = 0; i < P; i++)
		disjoint[i][0] = i;
	for (int i = 0; i < Q; i++)
		disjoint[i][1];
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
	scanf("%d%d%d%d", &N, &M, &P, &Q);
	construct();
	int a, b, c;
	for (int i = 0; i < P; i++) {
		scanf("%d%d%d", &a, &b, &c);
		--a; --b;
		edges.push_back(edge{ 0,a,b,c });
	}
	for (int i = 0; i < P; i++) {
		scanf("%d%d%d", &a, &b, &c);
		--a; --b;
		edges.push_back(edge{ 1,a,b,c });
	}
	sort(edges.begin(), edges.end());
	ll cost = 0, nEdges = 0, hEdges = 0, vEdges = 0;
	for (edge e : edges) {
		if (!cmp(e.a, e.b, e.type)) {
			cost += (e.type ? P - hEdges : Q - vEdges)*e.w;
			nEdges += e.type ? vEdges++ : hEdges++;
		}
	}
	return 0;
}