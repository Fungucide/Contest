/*
*Standard Disjoint Set
*/

#ifdef DMOJ

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

#endif

#define MAXN 100000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, disjoint[MAXN];

void construct() {
	for (int i = 0; i < N; i++)
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
	scan(N);
}