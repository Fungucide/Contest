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

#define MAXN 15//1e5
#define MAXQ 20000
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, Q,stack[MAXQ][MAXN];//Query Number , Index

int main() {
	scan(N);scan(Q);
	for (int i = 0;i < Q;i++) {
		if (i != 0)
			getchar();
		for (int j = 0;j < N;j++) {
			stack[i][j] = getchar() - '0';
		}
	}

	return 0;
}