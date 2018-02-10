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

ll M, N, Q, seg[2 * MAXN], lazy[MAXN], segSize[2 * MAXN], h = 0;

//NOTE: Current Seg tree is for addition, modifications will need to be made for other operations all parts marked will require editing

template <typename T>
void construct(T *t, T(*combiner)(T, T), bool lt) {
	for (int i = N - 1; i > 0; --i)
		t[i] = combiner(t[i << 1], t[i << 1 | 1]);
	for (h = 0; N >> h > 0; h++);
	if (lt) {
		for (int i = 2 * N - 1; i >= N; i--)
			segSize[i] = 1;
		for (int i = N - 1; i > 0; i--)
			segSize[i] = segSize[i << 1] + segSize[i << 1 | 1];
	}
}

template <typename T>
void apply(T *t, T *d, int p, int v) {
	t[p] = (t[p] + v * segSize[p]) % M;
	if (p < N)
		d[p] = (d[p] + v) % M;
}

template <typename T>
void build(T *t, T *d, int p, T(*combiner)(T, T)) {
	while (p > 1) {
		p >>= 1;
		t[p] = (combiner(t[p << 1], t[p << 1 | 1]) + d[p] * segSize[p]) % M;// This might need to be changed depending on the combiner RN: multiply by segSize because of addition
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
void update(T *t, T *d, int l, int r, int value, T(*combiner)(T, T)) {
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
T query(T *t, T*d, int l, int r, T(*combiner)(T, T)) {
	l += N;
	r += N;
	push(t, d, l);
	push(t, d, r - 1);
	T res; // Change this when changing combiner
	bool flag=false;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l & 1) {
			res = flag ? combiner(res, t[l]) : t[l]%M;
			l++;
			flag = true;
		}
		if (r & 1) {
			--r;
			res = flag ? combiner(t[r], res) : t[r]%M;
			flag = true;
		}
	}
	return res;
}

ll sum(ll a, ll b) {
	return (a + b) % M;
}

int main() {
	scan(M); scan(N); scan(Q);
	int a, b, c;
	ll d;
	for (int i = 0; i < N; i++)
		scan(seg[N + i]);
	construct(seg, sum, true);
	for (int i = 0; i < Q; i++) {
		scan(a); scan(b); scan(c);
		--b;
		if (a == 1) {
			scan(d);
			update(seg, lazy, b, c, d, sum);
		}
		else {
			ll res = query(seg, lazy, b, c, sum) % M;
			printf("%lld\n", res);

		}
	}
	return 0;
}