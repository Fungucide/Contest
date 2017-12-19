/*
*Standard Seg Tree for addition
*/

#include <stdio.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 1

int N, seg[2 * MAXN];

void build() {
	for (int i = N - 1; i > 0; --i)
		seg[i] = seg[i << 1] + seg[i << 1 | 1];
}

void modify(int p, int value) {
	for (seg[p += N] = value; p > 1; p >>= 1)
		seg[p >> 1] = seg[p] + seg[p ^ 1];
}

int query(int l, int r) {  // sum on interval [l, r)
	int res = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1)
			res += seg[l++];//Warning: sometimes this misbehaves
		if (r & 1)
			res += seg[--r];
	}
	return res;
}

int main() {
	scan(N);
	return 0;
}