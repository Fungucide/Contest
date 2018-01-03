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
#define _CRT_SECURE_NO_WARNINGS

#endif

#define MAXN 100002//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N;
bool nprime[MAXN];

int main() {
	scan(N);
	nprime[0] = true;
	nprime[1] = true;
	for (int i = 2; i < MAXN;i++) {
		if (!nprime[i]) {
			for (int j = i << 1;j < MAXN;j += i) {
				nprime[j] = true;
			}
		}
	}
	int num, res = 0;
	for (int i = 0; i < N;i++) {
		scan(num);
		if (!nprime[num])
			res++;
	}
	printf("%d\n", res);
	return 0;
}