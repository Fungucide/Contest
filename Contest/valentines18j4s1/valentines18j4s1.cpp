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
#define MAXN 100000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N,M;

bool isCust(int n) {
	int inv=0,num=n,dig;
	while (num > 0) {
		dig = num % 10;
		inv = inv * 10 + dig;
		num /= 10;
	}
	return n == inv;
}

int main() {
	scan(N); scan(M);
	int avr = (N + M) >> 1;
	for (int i = 0; i < M; i++) {
		if (isCust(avr+i)) {
			printf("%d\n", avr+i);
			return 0;
		}else if (isCust(avr - i)) {
			printf("%d\n", avr-i);
			return 0;
		}
	}
	return 0;
}