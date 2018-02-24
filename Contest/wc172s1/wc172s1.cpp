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
#define MAXN 400001//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, M, G[MAXN], L[MAXN],kust=0;
vector<int> Gcust, Lcust,cust;
unordered_map<int, int> comp,rev;

int main() {
	scan(N); scan(M);
	int a;
	for (int i = 0; i < N; i++) {
		scan(a);
		Lcust.push_back(a);
		cust.push_back(a);
	}
	for (int i = 0; i < M; i++) {
		scan(a);
		Gcust.push_back(a);
		cust.push_back(a);
	}
	sort(cust.begin(), cust.end());
	for (int i : cust) {
		if (comp.find(i) == comp.end()) {
			rev[kust] = i;
			comp[i] = kust++;
		}
	}
	for (int i:Lcust)
		L[comp[i]]++;
	for (int i : Gcust)
		G[comp[i]]++;

	for (int i = 1; i < MAXN; i++) {
		G[i] += G[i - 1];
		L[i] += L[i - 1];
	}
	for (int i = 0; i < MAXN; i++) {
		if (N - L[i] < M - G[i]) {
			printf("%d\n",rev[i]+1);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}