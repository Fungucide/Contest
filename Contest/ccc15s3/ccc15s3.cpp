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
#include <set>
#define scanf scanf_s

#endif

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define MAXN 100000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int G, P;
set<int> s;

int main() {
	scan(G);scan(P);
	int gate;
	for (int i = 0; i < P;i++) {
		scan(gate);
		s.upper_bound(gate);
		printf("%d\n", s.upper_bound(gate));
	}
	return 0;
}