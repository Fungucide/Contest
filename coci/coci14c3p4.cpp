#include <stdio.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 500001

using namespace std;
int N, a[MAXN], b[MAXN], temp[651][651], psa[651][651];

int q(int a, int b, int c, int d) {
	if (c < 0 || d < 0)
		return 0;
	int res = psa[c][d];
	if (a > 0)
		res -= psa[a - 1][d];
	if (b > 0)
		res -= psa[c][b - 1];
	if (a > 0 && b > 0)
		res += psa[a - 1][b - 1];
	return res;
}

int main() {
	scan(N);
	for (int i = 0; i < N; ++i) {
		scan(a[i]); scan(b[i]);
		temp[a[i]][b[i]]++;
	}
	for (int i = 0; i <= 650; i++)
		for (int j = 0; j <= 650; j++) {
			psa[i][j] = temp[i][j];
			if (i > 0)
				psa[i][j] += psa[i - 1][j];
			if (j > 0)
				psa[i][j] += psa[i][j - 1];
			if (i > 0 && j > 0)
				psa[i][j] -= psa[i - 1][j - 1];
		}

	for (int i = 0; i < N; i++) {
		printf("%d ", q(a[i] + 1, b[i] + 1, 650, 650) + 1);
		printf("%d\n", N - q(0, 0, a[i] - 1, b[i] - 1) - temp[0][b[i]] * (a[i] == 650) - temp[a[i]][0] * (b[i] == 650));
	}
	return 0;
}
