// ccc16s3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <list>
#include <queue>
#define MAX 100001

using namespace std;

int edges[MAX],n, m, e, maxD, idx = -1;
bool isP[MAX], isValid[MAX],v1[MAX],v2[MAX];
list <int>adj[MAX];


int main()
{
	scanf_s("%d %d", &n, &m);
	e = n - 1;
	int a, b;
	for (int i = 0; i < m;i++) {
		scanf_s("%d", &a);
		isP[a] = true;
	}
	for (int i = 0;i < n-1;i++) {
		isValid[i] = true;
		scanf_s("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		edges[a]++;
		edges[b]++;
	}
	isValid[n - 1]=true;
	
	queue <int>next;
	for (int i = 0;i < n;i++) {
		if (adj[i].size() <= 1) {
			next.push(i);
		}
	}
	int vEdges;
	while (!next.empty()) {
		int num = next.front();
		next.pop();
		if (!isP[num]&&isValid[num]) {
			if (edges[num] <= 1) {
				isValid[num] = false;
				e--;
				for(int i:adj[num])
					if (isValid[i]) {
						edges[i]--;
						next.push(i);
					}
			}
		}
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < n;i++) {
		if (isValid[i]) {
			q.push({ i,0 });
			break;
		}
	}

	while (!q.empty()) {
		int num = q.front().first;
		int d = q.front().second;
		q.pop();
		if (isP[num] && d > maxD) {
			maxD = d;
			idx = num;
		}
		for (int i : adj[num]) {
			if (isValid[i]&&!v1[i])
				q.push({ i,d + 1 });
		}
		v1[num] = true;
	}

	q.push({ idx,0 });

	while (!q.empty()) {
		int num = q.front().first;
		int d = q.front().second;
		q.pop();
		if (isP[num] && d > maxD) {
			maxD = d;
		}
		for (int i : adj[num]) {
			if (isValid[i]&&!v2[i])
				q.push({ i,d + 1 });
		}
		v2[num] = true;
	}

	int res = e * 2 - maxD;
	printf("%d\n", res);
	return 0;
}

