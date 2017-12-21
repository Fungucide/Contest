#include <stdio.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 1

int h = sizeof(int) * 8 - __builtin_clz(n);
int n, t[2 * MAXN], d[MAXN];

void apply(int p, int value) {
	t[p] += value;
	if (p < n) d[p] += value;
}

void build(int p) {
	while (p > 1) {
		p >>= 1;
		t[p] = max(t[p << 1], t[p << 1 | 1]) + d[p];
	}
}

void push(int p) {
	for (int s = h; s > 0; --s) {
		int i = p >> s;
		if (d[i] != 0) {
			apply(i << 1, d[i]);
			apply(i << 1 | 1, d[i]);
			d[i] = 0;
		}
	}
}

void inc(int l, int r, int value) {
	l += n, r += n;
	int l0 = l, r0 = r;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l & 1) apply(l++, value);
		if (r & 1) apply(--r, value);
	}
	build(l0);
	build(r0 - 1);
}

int query(int l, int r) {
	l += n, r += n;
	push(l);
	push(r - 1);
	int res = -2e9;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = max(res, t[l++]);
		if (r & 1) res = max(t[--r], res);
	}
	return res;
}

int main() {

}