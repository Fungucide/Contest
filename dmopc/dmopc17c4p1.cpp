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

int N, Q, cust[MAXN];

int main() {
	scan(N); scan(Q);
	int a, b;
	for (int i = 0; i < Q; i++) {
		scan(a); scan(b);
		cust[a] ++;
		cust[b] --;
	}
	int paint = 0, total = 0;
	for (int i = 0; i < N; i++) {
		paint += cust[i];
		if (paint)
			total++;
	}
	printf("%d %d\n",N-total ,total);
	return 0;
}