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
#define MAXN 100000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, cust, cost = 0, f;

int main() {
	scan(N);
	while (N > 1) {
		cust = sqrt(N) + 1;
		f = 2;
		while (N%f != 0 && f <= cust)
			f++;
		if (N%f == 0&&f<N) {
			int kust = N / f;
			N -= kust;
			cost += N / kust;
		}
		else {
			N--;
			cost += N;
		}
	}
	printf("%d\n", cost);
	return 0;
}