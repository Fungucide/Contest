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
#define MAXN 15//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, disjoint[MAXN],maxP;
unordered_map<string, int> name;
priority_queue<pair<int, pii>> pq;

void construct() {
	for (int i = 0; i <= 14; i++)
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

void merge(int x, int y) {
	disjoint[find(y)] = find(x);
}

int main() {
	cin >> N;
	construct();
	name["Park"] = 0;
	string a, b;
	int c;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		if (name.find(a) == name.end())
			name[a] = name.size();
		if (name.find(b) == name.end())
			name[b] = name.size();

		pq.push({ -c,{name[a],name[b]} });
	}
	cin >> maxP;
	int cost = 0;
	int pCon = 0;
	int nEdges = 0;
	while (!pq.empty()&&nEdges!=name.size()-1) {
		pair<int, pii> e = pq.top();
		pq.pop();
		if (!cmp(e.second.first, e.second.second)) {
			if ((e.second.first == 0 || e.second.second == 0) && pCon + 1 > maxP)
				continue;
			cost -= e.first;
			merge(e.second.first, e.second.second);
			nEdges++;
			if (e.second.first == 0 || e.second.second == 0)
				pCon++;
		}
	}
	if (nEdges != name.size() - 1)
		printf("Cust\n");
	printf("Total miles driven: %d\n", cost);
	return 0;
}