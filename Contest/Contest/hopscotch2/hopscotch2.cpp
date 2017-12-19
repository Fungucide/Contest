#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <algorithm>
#include <stack>
#define MAXN 2<<24+1

using namespace std;

int N, K, R[MAXN], dp[MAXN];
stack<int> best, dps[MAXN];

int f(int idx) {
	if (idx > N)
		return 0;
	if (dp[idx] == -1) {
		if (idx + 1 + K > N) {
			return R[idx + 1];
		}
		int min = 1 << 30;
		stack<int> org = dps[idx];
		for (int i = idx + 1;i <= idx + K;i++) {
			int res = R[i] + f(i);
			if (res < min)
				min = res;
		}
		dp[idx] = min;
	}
	return dp[idx];
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N;i++) {
		scanf("%d", &R[i]);
	}
	memset(dp, -1, sizeof dp);
	printf("%d", f(0, 0));
	scanf("%*d");
	return 0;
}