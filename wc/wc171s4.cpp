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
#define MAXN 1000000002//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int K, N, dp[2005][2005];//Sum%coin
bool notUse[MAXN];

inline int f(int sum, int lCoin) {
	if (sum == 0)
		return 0;
	if (dp[sum][lCoin] == -1) {
		int res = 1;
		for (int i = 2; i < lCoin; i++) {
			if (notUse[i])
				continue;
			res = max(f(sum%i, i) + 1, res);
		}
		dp[sum][lCoin] = res;
	}
	return dp[sum][lCoin];
}

int main() {
	memset(dp, -1, sizeof dp);
	scan(K); scan(N);
	int a;
	for (int i = 0; i < N; i++) {
		scan(a);
		notUse[a] = true;
	}
	int res = 0;
	for (int i = 2; i < K; i++) {
		if (notUse[i])
			continue;
		res = max(f(K%i, i), res);
	}
	printf("%d\n", res);
	return 0;
}