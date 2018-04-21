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
#define MAXN 100000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, M, K;

int main() {
	scan(N); scan(M); scan(K);
	int best = M * (N - 1) + 2 * (M - 1);
	int cust = (M-1);
	if (cust <= K) {
		printf("%d\n", best - K);
	}
	else {
		K = cust - K;
		printf("%d\n", best - cust - (N-1)*(K));
	}
	return 0;
}