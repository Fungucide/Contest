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
#define scanf scanf_s

#endif

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define MAXN 100002//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int T, e[MAXN], o[MAXN];

int main() {
	scan(T);
	for (int c = 1; c <= T; c++) {
		int N;
		scan(N);
		for (int i = 0; i < N; i++) {
			if (i & 1)
				scan(o[i>>1]);
			else
				scan(e[i>>1]);
		}
		bool cust = true;
		int w = -1;

		sort(o, o + (N >> 1));
		sort(e, e + (N >> 1) + (N&1));
		int prev = -1;
		for (int i = 0; i < N; i++) {
			if (prev > ((i & 1) ? o[i >> 1] : e[i >> 1])) {
				w = i-1;
				cust = false;
				break;
			}
			prev = ((i & 1) ? o[i >> 1] : e[i >> 1]);
		}

		if (cust)
			printf("Case #%d: OK\n", c);
		else
			printf("Case #%d: %d\n", c, w);
	}
	return 0;
}