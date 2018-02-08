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
#define MAXN 10000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, seg[2 * MAXN];

template <typename T>
void construct(T *t, T(*combiner)(T, T)) {
	for (int i = N - 1; i > 0; --i)
		t[i] = combiner(t[i << 1], t[i << 1 | 1]);
}

template <typename T>
void modify(int p, T value, T *t, T(*combiner)(T, T)) {
	for (t[p += n] = value; p > 1; p >>= 1)
		t[p >> 1] = combiner(t[p], t[p ^ 1]);
}

template <typename T>
T query(int l, int r, T *t, T(*combiner)(T, T)) {
	T res;
	bool flag = false;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1)
			(res = flag ? combiner(res, t[l++]) : t[l++]), flag = true;
		if (r & 1)
			(res = flag ? combiner(res, t[--r]) : t[--r]), flag = true;
	}
	return res;
}

int main() {
	scan(N);
	return 0;
}