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

#define MAXN 50003//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

list<int> adj[MAXN];
unordered_map<int, vector<int>> start[MAXN];
int N, Q, h[MAXN], bright[MAXN];

void dfs(int n, int hei, int par) {
	h[n] = hei;
	for (int i : adj[n]) {
		if (i == par)
			continue;
		dfs(i, hei + 1, n);
	}
}

int main() {
	scan(N);scan(Q);
	for (int i = 0; i < N;i++) {
		scan(bright[i + 1]);
	}
	int a, b;
	for (int i = 1;i < N;i++) {
		scan(a);scan(b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0, -1);

	for (int i = 0; i < Q;i++) {
		scan(a);scan(b);
		vector<int> v;
		bool custed = false;
		int abal = -1, bbal = -1;
		while (h[a] != h[b]) {
			if (h[a] > h[b]) {
				for (int j : adj[a])
					if (h[j] < h[a]) {
						v.push_back(bright[a]);
						a = j;
						break;
					}
			}
			else if (h[b] > h[a]) {
				for (int j : adj[b])
					if (h[j] < h[b]) {
						v.push_back(bright[b]);
						b = j;
						break;
					}
			}
		}
		vector<int> cus;
		abal = a;bbal = b;
		while (a != b) {
			if (start[a].find(b) != start[a].end()) {
				vector<int> custsu = start[a][b];
				v.insert(end(v), begin(custsu), end(custsu));
				custed = true;
				break;
			}
			for (int j : adj[a])
				if (h[j] < h[a]) {
					cus.push_back(bright[a]);
					a = j;
					break;
				}
			for (int j : adj[b])
				if (h[j] < h[b]) {
					cus.push_back(bright[b]);
					b = j;
					break;
				}
		}
		if (!custed) {
			cus.push_back(bright[a]);
			start[abal][bbal] = cus;
			start[bbal][abal] = cus;
			v.insert(end(v), begin(cus), end(cus));
		}
		sort(v.begin(), v.end());
		int small = -1;
		for (int i = 1;i < v.size();i++) {
			if (small == -1 || v[i] - v[i - 1] < small)
				small = v[i] - v[i - 1];
		}
		printf("%d\n", small);
	}
	return 0;
}