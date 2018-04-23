#include <stdio.h>
#include <algorithm>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int N, M, K, dp[1000001][501], order[1000001];

int f(int day, int k, int m[]) {
	if (dp[day][k] == -1) {
		m[order[day]]++;
		if (k > 0) {
			dp[day][k] = f(day + 1, k - 1, m);
		}
		int res = m[order[day]] + f(day + 1, k, m);
		if (res < dp[day][k])
			dp[day][k] = res;
	}
	return dp[day][k];
}

int main() {
	scan(N); scan(M); scan(K);
	for (int i = 0; i < N; i++) {
		scan(order[i]);
	}
	int m[100];
	printf("%d\n", f(0, K, m));
	return 0;
}