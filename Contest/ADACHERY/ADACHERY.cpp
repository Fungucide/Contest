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
#include <unordered_set>
#include <queue>
#define scanf scanf_s

#endif

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define MAXN 100000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, M;
vector<int> adj[MAXN];
unordered_set<int> con[MAXN];

int main() {
	scan(N); scan(M);
	int a, b;
	for (int i = 0; i < M; i++) {
		scan(a); scan(b);
		adj[--a].push_back(--b);
		con[a].insert(b);
		con[a].insert(a);
	}
	for (int i = 0; i < N; i++) {
		for (int e : adj[i])
			if (con[i].find(e) == con[i].end())
	}
	return 0;
}