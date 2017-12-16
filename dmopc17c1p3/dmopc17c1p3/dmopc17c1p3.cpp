// dmopc17c1p3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <list>
#include <queue>
#include <string>
#include <functional>
#define MAXN 100002

using namespace std;

struct w {
	int u, l, n;
	bool operator<(const w& rhs) const {
		if (u != rhs.u) {
			return u > rhs.u;
		}
		else {
			return l > rhs.l;
		}
	}
};

list<pair<int, int>> adj[MAXN];
bool v[MAXN];
int d[MAXN][2];
int n, m;

int main()
{
	memset(d, -1, sizeof d);
	scanf_s("%d%d", &n, &m);
	int a, b, c;
	for (int i = 0; i < m;i++) {
		scanf_s("%d%d%d", &a, &b, &c);
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	priority_queue<w> pq;//Weight(Unsafe,Total) Then Node
	pq.push({ 0,0,1 });
	d[1][0] = 0;
	d[1][1] = 0;
	while (!pq.empty()) {
		int u = pq.top().u;
		int l = pq.top().l;
		int n = pq.top().n;
		pq.pop();
		for (pair<int, int> i : adj[n]) {
			if (!v[i.first]) {
				if (d[i.first][1] == -1 || d[i.first][0] > u + i.second || (d[i.first][0] == u + i.second && d[i.first][1] > l + 1)) {
					d[i.first][1] = l + 1;
					d[i.first][0] = u + i.second;
					pq.push({ u + i.second ,l + 1,i.first });
				}
			}
		}
		v[n] = true;
	}

	if (d[n][0] == -1) {
		printf("-1\n");
	}
	else {
		printf("%d %d\n", d[n][0], d[n][1]);
	}

	return	0;
}
