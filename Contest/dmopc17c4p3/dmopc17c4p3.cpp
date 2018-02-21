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
#define scanf scanf_s

#endif

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAXN 100000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

ll N, idx1, idx2, d1[MAXN], d2[MAXN], d3[MAXN];
vector<pll> adj[MAXN];
queue<pii> q;

int main() {
	scan(N);
	ll a, b, c;
	for (int i = 1; i < N; i++) {
		scan(a); scan(b); scan(c);
		adj[--a].push_back({ --b,c });
		adj[b].push_back({ a,c });
	}

	q.push({ 0,-1 });
	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		for (pii e : adj[cur.first]) {
			if (e.first == cur.second)
				continue;
			d1[e.first] = d1[cur.first] + e.second;
			if (d1[idx1] < d1[e.first])
				idx1 = e.first;
			q.push({ e.first, cur.first });
		}
	}

	q.push({ idx1,-1 });
	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		for (pii e : adj[cur.first]) {
			if (e.first == cur.second)
				continue;
			d2[e.first] = d2[cur.first] + e.second;
			if (d2[idx2] < d2[e.first])
				idx2 = e.first;
			q.push({ e.first, cur.first });
		}
	}

	q.push({ idx2,-1 });
	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		for (pii e : adj[cur.first]) {
			if (e.first == cur.second)
				continue;
			d3[e.first] = d3[cur.first] + e.second;
			q.push({ e.first, cur.first });
		}
	}

	ll big = 0;
	for (int i = 0; i < N; i++) {
		if (i == idx2)
			continue;
		big = max(big, d2[i]);
	}
	for (int i = 0; i < N; i++) {
		if (i == idx1)
			continue;
		big = max(big, d3[i]);
	}
	

	printf("%lld\n", big);

	return 0;
}