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
#define MAXN 100000

using namespace std;

int N;
unordered_map<int, ll> dp;

inline ll f(int n) {
	if (dp.find(n) == dp.end()) {
		ll res = 0;
		for (int i = n; i != 1; i = n / (n / i + 1))
			res += f(n / i)*(i - n / (n / i + 1));
		dp[n] = res;
	}
	return dp[n];
}

int main() {
	dp[1] = 1;
	scanf("%d", &N);
	printf("%lld\n", f(N));
	return 0;
}