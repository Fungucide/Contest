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
#include <unordered_set>
#define _CRT_SECURE_NO_WARNINGS

#endif

#define MAXN 100000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int L, R;
unordered_set<int> used;

int s(int n) {
	if (n < 10)
		return n;
	return n % 10 + s(n / 10);
}

int main() {
	scan(L);scan(R);
	if (R - L + 1 < 10)
		printf("%d\n", R - L + 1);
	else {
		int uniq = 0;
		for (int i = L;i <= R;i++) {
			int res = s(i);
			if (used.find(res) == used.end()) {
				uniq++;
				used.insert(res);
			}
		}
		printf("%d\n", uniq);
	}
	return 0;
}