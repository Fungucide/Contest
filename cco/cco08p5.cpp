#include <stdio.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAX 101
#define ll long long

int N, val[MAX][2], dp[MAX][MAX * 500 * 200];

int f(int idx, ll dif) {
	if (idx >= N)
		return dif;
	if (dp[idx][dif] == )
}

int main() {
	scan(N);
	for (int i = 0; i < N; i++) {
		scan(val[i][0]); scan(val[i][1]);
	}
	printf("%d\n", f(0, 0));
	return 0;
}