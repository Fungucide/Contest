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
#define MAXN 100005

using namespace std;

int N, M, P, Q, disjoint[MAXN];

vector<node> interCity, interPlanet;

struct node {
	int a, b, w;
	bool operator<(const node& rhs) const { if (w != rhs.w) { return w < rhs.w; } else { return a > rhs.a; } }
};

void construct(int cust) {
	for (int i = 0; i < cust; i++)
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

int main() {
	scanf("%d%d%d%d", &N, &M, &P, &Q);
	int a, b, c;
	construct(P);
	int citySave = 0;
	for (int i = 0; i < P; i++) {
		scanf("%d%d%d", &a, &b, &c);
		--a; --b;
		interCity.push_back(node{ a,b,c });
	}
	sort(interCity.begin(), interCity.end());
	for (node e : interCity) {
		if (!cmp(e.a, e.b)) {
			merge(e.b, e.a);
		}
		else {
			citySave += e.w;
		}
	}
	construct(Q);
	int planetSave = 0;
	for (int i = 0; i < P; i++) {
		scanf("%d%d%d", &a, &b, &c);
		--a; --b;
		interPlanet.push_back(node{ a,b,c });
	}
	sort(interPlanet.begin(), interPlanet.end());
	for (node e : interPlanet) {
		if (!cmp(e.a, e.b)) {
			merge(e.b, e.a);
		}
		else {
			planetSave += e.w;
		}
	}
	return 0;
}