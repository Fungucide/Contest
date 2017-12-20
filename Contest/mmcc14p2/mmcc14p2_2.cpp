#include <iostream>
#include <string>
#include <algorithm>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MIN(a,b) (a<b?a:b)
#define MAXN 2005
#define MAXM 5005

using namespace std;

int N, M, Q, rSwap[MAXN], seg[2 * MAXN], point[2 * MAXN], cRes[MAXN][MAXN];
string grid[MAXN];

int comp(int a, int b, int max) {
	a = rSwap[point[a]];
	b = rSwap[point[b]];
	if (cRes[a][b] == -1) {
		int res = 0;
		for (; res < M; res++)
			if (grid[a][res] != grid[b][res])
				break;
		cRes[a][b] = res;
		cRes[b][a] = res;
	}
	return MIN(cRes[a][b], max);
}

void build() {
	for (int i = N - 1; i > 0; --i) {
		point[i] = point[i << 1];
		seg[i] = comp(i << 1, i << 1 | 1, MIN(seg[i << 1], seg[i << 1 | 1]));
	}
}

void update(int p) {
	for (p += N; p > 1; p >>= 1)
		seg[p >> 1] = comp(p, p ^ 1, MIN(seg[p], seg[p ^ 1]));
}

int query(int l, int r) {  // sum on interval [l, r)
	int res = M + 1;
	int org = l + N;
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
	ios::sync_with_stdio(0);
	scan(N); scan(M);
	memset(cRes, -1, sizeof cRes);
	for (int i = 0; i < N; i++) {
		rSwap[i] = i;
		seg[N + i] = M;
		point[N + i] = i;
		cin >> grid[i];
		getchar();
	}
	build();
	scan(Q);
	int a, b;
	for (int i = 0; i < Q; i++) {
		scan(a); scan(b);
		if (a == b) {
			printf("%d\n", M);
			continue;
		}
		a--;
		printf("%d\n", query(a, b)*abs(a - b));
		b--;
		swap(rSwap[a], rSwap[b]);
		update(a);
		update(b);
	}

	return 0;
}