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

#define MAXN 20003//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pii pair<int,int>

using namespace std;

int N, M, len[MAXN], rev[MAXN];
vector<pii> adj[MAXN], radj[MAXN];
priority_queue <pii, vector<pii>, greater<pii>> pq;

int main() {
	scan(N); scan(M);
	int a, b, c;
	for (int i = 0; i < M; i++) {
		scan(a); scan(b); scan(c);
		adj[a].push_back({ b,c });
		radj[b].push_back({ a,c });
	}

	memset(len, -1, sizeof len);
	memset(rev, -1, sizeof rev);

	len[1] = 0;
	pq.push({ 0,1 });

	while (!pq.empty()) {
		pii p = pq.top();
		pq.pop();
		for (pii e : adj[p.second])
			if (len[e.first] == -1 || len[e.first]>p.first + e.second) {
				len[e.first] = p.first + e.second;
				pq.push({ len[e.first],e.first });
			}
	}

	if (len[N] == -1) {
		printf("-1\n");
		return 0;
	}

	rev[N] = 0;
	pq.push({ 0,N });

	while (!pq.empty()) {
		pii p = pq.top();
		pq.pop();
		for (pii e : radj[p.second])
			if (rev[e.first] == -1 || rev[e.first] > p.first + e.second) {
				rev[e.first] = p.first + e.second;
				pq.push({ rev[e.first],e.first });
			}
	}

	int mDis = len[N];
	int	secondMin = 1 << 30;
	int temp;
	for (int i = 1; i <= N; i++)
		for (pii e : adj[i])
			if (len[i] != -1 && rev[e.first] != -1 && (temp = len[i] + rev[e.first] + e.second) != mDis)
				secondMin = secondMin < temp ? secondMin : temp;

	if (secondMin == 1 << 30)
		printf("-1\n");
	else
		printf("%d\n", secondMin);

	return 0;
}