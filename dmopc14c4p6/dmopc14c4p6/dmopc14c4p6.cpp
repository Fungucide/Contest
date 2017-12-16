// dmopc14c4p6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <list>
#include <queue>
#define MAXN 500002

using namespace std;

int d1[MAXN], d2[MAXN];
list<int> adj[MAXN];
int n;

int main()
{
	scanf_s("%d",&n);
	memset(d1, -1, n);
	int a, b;
	for (int i = 0; i < n-1;i++) {
		scanf_s("%d%d", &a, &b);
		adj[--a].push_back(--b);
		adj[b].push_back(a);
	}
	int idx1 = -1;
	int md1 = -1;
	queue<int> q1;
	q1.push(1);
	d1[1] = 0;
	while (!q1.empty()) {
		int idx = q1.front();
		q1.pop();
		for (int i : adj[idx]) {
			if (d1[i] == -1) {
				d1[i] = d1[idx]+1;
				if (d1[i]>md1) {
					md1 = d1[i];
					idx1 = i;
				}
			}
		}
	}

	int idx2 = -1;
	int md2 = -1;
	queue<int> q2;
	q2.push(idx1);
	d2[idx1] = 0;
	while (!q2.empty()) {
		int idx = q2.front();
		q2.pop();
		for (int i : adj[idx]) {
			if (d2[i] == -1) {
				d2[i] = d2[idx] + 1;
				if (d2[i]>md2) {
					md2 = d2[i];
					idx2 = i;
				}
			}
		}
	}
	for (int i = 0;i < n;i++) {
		if (d1[idx1]-d1[i]>d2[i]) {
			printf("%d", d1[idx1] - d1[i]);
		}
		else {
			printf("%d", d2[i]);
		}
	}
    return 0;
}

