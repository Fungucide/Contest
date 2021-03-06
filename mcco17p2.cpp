#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
#include <stack>
#include <set>
#define scanf scanf_s

#endif

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define MAXN 200005//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

ll N, K, Q, seg[2 * MAXN], lazy[MAXN], segSize[2 * MAXN], h = 0;

//NOTE: Current Seg tree is for addition, modifications will need to be made for other operations all parts marked will require editing

template <typename T>
void construct(T *t, T(*combiner)(T, T), bool segS) {
	for (int i = N - 1; i > 0; --i)
		t[i] = combiner(t[i << 1], t[i << 1 | 1]);
	for (h = 0; N >> h > 0; h++);
	if (segS) {
		for (int i = 2 * N - 1; i >= N; i--)
			segSize[i] = 1;
		for (int i = N - 1; i > 0; i--)
			segSize[i] = segSize[i << 1] + segSize[i << 1 | 1];
	}
	else
		for (int i = 0; i < MAXN << 1; i++)
			segSize[i] = 1;
}

template <typename T>
void apply(T *t, T *d, int p, T v) {
	t[p] += v * segSize[p];
	if (p < N)
		d[p] += v;
}

template <typename T>
void build(T *t, T *d, int p, T(*combiner)(T, T)) {
	while (p > 1) {
		p >>= 1;
		t[p] = combiner(t[p << 1], t[p << 1 | 1]) + d[p] * segSize[p];
	}
}

template <typename T>
void push(T *t, T*d, int p) {
	for (int s = h; s > 0; --s) {
		int i = p >> s;
		if (i < N && d[i] != 0) {
			apply(t, d, i << 1, d[i]);
			apply(t, d, i << 1 | 1, d[i]);
			d[i] = 0;
		}
	}
}

template <typename T>
void update(T *t, T *d, int l, int r, T value, T(*combiner)(T, T)) {
	l += N, r += N;
	int l0 = l, r0 = r;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l & 1) {
			apply(t, d, l, value);
			l++;
		}
		if (r & 1) {
			r--;
			apply(t, d, r, value);
		}
	}
	build(t, d, l0, combiner);
	build(t, d, r0 - 1, combiner);
}

template <typename T>
T query(T *t, T*d, int l, int r, T(*combiner)(T, T),T res = 0) {
	l += N;
	r += N;
	push(t, d, l);
	push(t, d, r - 1);
	for (; l < r; l >>= 1, r >>= 1) {
		if (l & 1) {
			res =combiner(res, t[l]);
			l++;
		}
		if (r & 1) {
			--r;
			res =combiner(t[r], res);
		}
	}
	return res;
}

ll max(ll a, ll b) {
	return a > b ? a : b;
}

ll min(ll a, ll b) {
	return a < b ? a : b;
}

int main() {
	scan(N); scan(K); scan(Q);
	ll a, b, c;
	construct(seg, max, false);
	for (int i = 0; i < Q; i++) {
		scan(a); scan(b); scan(c);
		if (a == 0) {
			if (b < N && b >= 0)
				update(seg, lazy, max(0, b - K + 1), b + 1, c, max);
		}
		else if (b < N && c > 0) {
			printf("%lld\n", query(seg, lazy, max(b, 0), min(c + 1, N), max));
		}
	}
	return 0;
}