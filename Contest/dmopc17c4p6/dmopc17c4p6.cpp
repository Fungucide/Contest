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
//#define MAXN 200005//1e5
#define MAXN 12
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

struct cust {
	int full, M, A, K, I;
	cust operator+(const cust &l) {
		int aFull = full + l.full;
		int aM = M + l.M;
		int aA = A + l.A;
		int aK = K + l.K;
		int aI = I + l.I;
		int small = min(aM, min(aA, min(aK, aI)));
		aFull += small;
		aM -= small;
		aA -= small;
		aK -= small;
		aI -= small;
		return { aFull,aM,aA,aK,aI };
	}
};

int N, Q, segSize[2 * MAXN], h = 0;
cust seg[2 * MAXN], lazy[MAXN];

//NOTE: Current Seg tree is for addition, modifications will need to be made for other operations all parts marked will require editing

template <typename T>
void construct(T *t, T(*combiner)(T, T), bool segS) {
	//for (int i = N - 1; i > 0; --i)
		//t[i] = combiner(t[i << 1], t[i << 1 | 1]);
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
	t[p] = cust{ v.full*segSize[p], v.M*segSize[p], v.A*segSize[p], v.K*segSize[p], v.I*segSize[p] };
	if (p < N)
		d[p] = v;
}

template <typename T>
void build(T *t, T *d, int p, T(*combiner)(T, T)) {
	while (p > 1) {
		p >>= 1;
		t[p] = combiner(t[p << 1], t[p << 1 | 1]) + cust{ d[p].full*segSize[p], d[p].M*segSize[p], d[p].A*segSize[p], d[p].K*segSize[p], d[p].I*segSize[p] };
	}
}

template <typename T>
void push(T *t, T*d, int p) {
	for (int s = h; s > 0; --s) {
		int i = p >> s;
		if (i < N && d[i].full != 0 && d[i].M != 0 && d[i].A != 0 && d[i].K != 0 && d[i].I != 0) {
			apply(t, d, i << 1, d[i]);
			apply(t, d, i << 1 | 1, d[i]);
			d[i] = { 0,0,0,0,0 };
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
T query(T *t, T*d, int l, int r, T(*combiner)(T, T), T res = 0) {
	l += N;
	r += N;
	push(t, d, l);
	push(t, d, r - 1);
	for (; l < r; l >>= 1, r >>= 1) {
		if (l & 1) {
			res = combiner(res, t[l]);
			l++;
		}
		if (r & 1) {
			--r;
			res = combiner(t[r], res);
		}
	}
	return res;
}

cust sum(cust l, cust r) {
	return l + r;
}

int main() {
	scan(N); scan(Q);
	construct(seg, sum, true);//True if size of segment is important
	int cmd, a, b;
	char c;
	for (int i = 0; i < Q; i++) {
		scan(cmd); scan(a); scan(b);
		--a;
		if (cmd == 1) {
			c = getchar();
			cust u;
			if (c == 'M')
				u = { 0,1,0,0,0 };
			else if (c == 'A')
				u = { 0,0,1,0,0 };
			else if (c == 'K')
				u = { 0,0,0,1,0 };
			else
				u = { 0,0,0,0,1 };
			update(seg, lazy, a, b, u, sum);
		}
		else {
			printf("%d\n", query(seg, lazy, a, b, sum, { 0,0,0,0,0 }).full);
		}
	}
	return 0;
}