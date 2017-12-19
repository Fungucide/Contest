#include <stdio.h>
#include <algorithm>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MIN(a,b) (a<b?a:b)
#define MAXN 2001
#define MAXM 5001

using namespace std;

int N, M, Q, rSwap[MAXN], seg[2 * MAXN],ref[MAXN];
char grid[MAXN][MAXM];

int comp(int a, int b, int max) {
	int res = 0;
	for (; res <= max && res < M;res++)
		if (grid[rSwap[a]][res] != grid[rSwap[b]][res])
			break;
	return res;
}

void build() {
	for (int i = N - 1; i > 0; --i)
		seg[i] = comp(i << 1, i << 1 | 1, MIN(seg[i << 1], seg[i << 1 | 1]));
}

void update(int p) {
	for (p += N; p > 1; p >>= 1)
		seg[p >> 1] = comp(p, p ^ 1, MIN(seg[p], seg[p ^ 1]));
}

int query(int l, int r) {  // sum on interval [l, r)
	int res = M - 1;
	int org = l;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) {
			res = comp(org, l, MIN(seg[l], res));
			l++;
		}
		if (r & 1) {
			r--;
			res = comp(org, r, MIN(seg[r], res));
		}
	}
	return res;
}


int main() {
	scan(N);scan(M);
	for (int i = 0; i < N;i++) {
		rSwap[i] = i;
		seg[N + i] = M;
		for (int j = 0;j < M;j++)
			grid[i][j] = getchar();
		getchar();
	}
	build();
	scan(Q);
	int a, b;
	for (int i = 0; i < Q;i++) {
		scan(a);scan(b);
		a--;b--;
		printf("%d\n", query(a, b + 1)*abs(a-b+1));
		swap(rSwap[a], rSwap[b]);
		update(a);
		update(b);
	}

	return 0;
}