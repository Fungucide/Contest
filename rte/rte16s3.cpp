// rte16s3.cpp : Defines the entry polong for the console application.
//

#include "stdafx.h"
#include <queue>
#include <iostream>
#define MAX 6000
using namespace std;

long n;
int nl[MAX];
int np[MAX];
long nw[MAX];
long adj[MAX][MAX];
long dp[MAX][MAX];

int lca(int a, int b) {
	if (a == b) {
		return a;
	}
	else if (dp[a][b] == -1) {
		if (nl[b] < nl[a]) {
			dp[a][b] = lca(np[a], b);
			dp[b][a] = dp[a][b];
		}
		else if (nl[b] > nl[a]) {
			dp[a][b] = lca(a, np[b]);
			dp[b][a] = dp[a][b];
		}
		else {
			dp[a][b] = lca(np[a], np[b]);
			dp[b][a] = dp[a][b];
		}
	}
	return dp[a][b];
}

int main()
{
	scanf_s("%l", &n);
	for (long i = 0; i < n - 1;i++) {
		long a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = c;
		adj[b][a] = c;
	}
	memset(dp, -1, sizeof(dp));
	np[0] = -1l;
	nl[0] = 0;
	nw[0] = 0l;
	queue<long> q;
	q.push(0);
	while (!q.empty()) {
		long c = q.front();
		q.pop();
		for (long i = 0; i < n; i++) {
			if (adj[c][i] != 0 && i != np[c]) {
				np[i] = c;
				nl[i] = nl[c] + 1;
				nw[i] = nw[np[i]] + adj[c][i];
				q.push(i);
			}
		}
	}
	long nq;
	scanf_s("%l", &nq);
	for (long i = 0;i < nq;i++) {
		int a, b;
		scanf_s("%l %l", &a, &b);
		long l = lca(a, b);
		long val = (long)nw[a] + (long)nw[b] - ()(nw[l] << 1);
		cout << val << "\n";
	}
	return 0;
}

