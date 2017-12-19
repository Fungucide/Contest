#include <stdio.h>
#include <algorithm>
#define MAX 51

#define scanf scanf_s

using namespace std;

int R, C, S, B, K, M, dp[MAX][MAX][MAX][MAX];

struct flake {
	int t, v, c, r;//Temp, Value, Index, Time
	bool operator<(const flake& rhs)const {
		return r < rhs.r;
	}
};

flake snow[MAX*MAX];

int f(int time, int idx, int l, int k, int t) {//Time Flake Index, Location, #of Flake,Temp
	if (k == K||idx>=S)
		return 0;
	if (dp[time][l][k][t] == 0) {
		int max = 0;
		for (int i = idx;i < S;++i) {
			if (t + snow[i].t < B && (snow[i].r - time)*M >= abs(snow[i].c - l)) {
				int res = f(snow[i].r, i + 1, snow[i].c, k + 1, t + snow[i].t) + snow[i].v;
				if (res > max)
					max = res;
			}
		}
		dp[time][l][k][t] = max;
	}
	return dp[time][l][k][t];
}

int main() {
	scanf("%d%d%d%d%d%d", &R, &C, &S, &B, &K, &M);
	int t, v, c, r;
	for (int i = 0; i < S;++i) {
		scanf("%d%d%d%d", &t, &v, &c, &r);
		snow[i] = flake{ t, v, c, r };
	}
	sort(snow, snow + S);
	printf("%d\n", f(0,0,0,0,0));
	return 0;
}