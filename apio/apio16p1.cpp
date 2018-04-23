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

#define MAXN 500//1e5
#define MOD 1000000007
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long

using namespace std;

ll N, boat[MAXN][2];
unordered_map<ll, ll> dp[MAXN];

ll f(ll n, ll size) {
	if (n == N)
		return 1;
	if (dp[n].find(size) == dp[n].end()) {
		ll res = 0;
		res += f(n + 1, size);
		res %= MOD;
		for (int i = max(size + 1, boat[n][0]);i <= boat[n][1];i++) {
			res += f(n + 1, i);
			res %= MOD;
		}
		dp[n][size] = res;
	}
	return dp[n][size];
}

int main() {
	scan(N);
	for (int i = 0; i < N;i++) {
		scan(boat[i][0]);scan(boat[i][1]);
	}
	printf("%lld\n", f(0, -1) - 1);
	return 0;
}