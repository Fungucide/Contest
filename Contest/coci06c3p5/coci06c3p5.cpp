#include <stdio.h>
#include <vector>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MOD 100000000
#define MAXN 10001

using namespace std;

int N, M, dp[MAXN];
bool g = false, calc[MAXN];
vector<int> adj[MAXN];

int f(int idx) {
	if (dp[idx] == -1) {
		int sum = 0;
		if (calc[idx])
			return -2;
		calc[idx] = true;
		for (int i : adj[idx]) {
			int res = f(i);
			if (res == -2)
				return -2;
			if (sum + res > MOD)
				g = true;
			sum = (sum + res) % MOD;
		}
		calc[idx] = false;
		dp[idx] = sum;
	}
	return dp[idx];
}

int main() {
	scan(N);scan(M);
	memset(dp, -1, sizeof dp);
	dp[1] = 1;
	int a, b;
	for (int i = 0; i < M;i++) {
		scan(a);scan(b);
		a--;b--;
		adj[a].push_back(b);
	}
	int res = f(0);
	if (res == -2)
		printf("inf\n");
	else if (g)
		printf("%.9d\n", res);
	else
		printf("%d\n", f(0));
	return 0;
}