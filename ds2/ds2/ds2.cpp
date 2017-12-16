// ds2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <vector>
#define MAXN 100001

using namespace std;

int disjoint[MAXN], n, m;
vector<pair<int, int>> edges;
vector<int> u;

void construct() {
	for (int i = 0; i < n; i++)
		disjoint[i] = i;
}

int find(int x) {
	if (disjoint[x] == x)
		return x;
	return disjoint[x] = find(disjoint[x]);
}

bool cmp(int x, int y) {
	return find(x) == find(y);
}

bool merge(int x, int y) {
	disjoint[find(y)] = find(x);
	return true;
}

int main()
{
	scanf_s("%d %d", &n, &m);
	construct();
	int a, b;
	for (int i = 0; i < m;i++) {
		scanf_s("%d %d", &a, &b);
		edges.push_back({ a,b });
	}
	construct();
	int e = 0;
	for (int i = 0; i < edges.size();i++) {
		if (!cmp(edges[i].first, edges[i].second)) {
			merge(edges[i].first, edges[i].second);
			e++;
			u.push_back(i);
		}
	}

	if (e == n - 1) {
		for (int i : u) {
			printf("%d\n", i + 1);
		}
	}
	else {
		printf("Disconnected Graph\n");
	}

	return 0;
}

