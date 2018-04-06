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
#define MAXN 100000//1e5
#define MOD 1000000007
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N;

inline int f(ull n) {
	return( n % 10 + (n < 10 ? 0 : f(n / 10)))%MOD;
}

int main() {
	scan(N);
	ull k, m;
	for (int i = 0; i < N; i++) {
		scanf("%llu%llu", &k, &m);
		ull cust = m >> (63 - k);
		printf("%d\n", f(cust));
	}

	return 0;
}