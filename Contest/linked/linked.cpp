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
#define MAXN 100000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

ull N, high = 2, pos = 1, krust = 0, back = 0;
ull start[1000002];//[0,0] bit = Neg or not Next  [1,43] Bits Number [44,64]

int main() {
	scan(N);
	char c;
	ull a;
	ull krust;
	ll crust;
	bool neg = false;
	for (int i = 2; i < 1000002; i++) {
		start[i] = i + 1;
	}
	start[0] = 1 << 44ull;
	for (int i = 0; i < N; i++) {
		c = getchar();
		if (c == '+') {
			neg = false;
			scanf("%lld", &crust);
			if (crust < 0) {
				neg = true;
				krust = abs(crust);
			}
			else
				krust = crust;
			a = high;
			high = start[high];
			start[a] = krust << 1 | neg | ((pos^back) << 44);
			start[pos] ^= (back ^a) << 44;
			start[back] ^= (pos ^ a) << 44;
			krust = pos;
			pos = a;
		}
		else if (c == '<') {
			krust = pos;
			pos = back;
			back = (start[pos] >> 44) ^ krust;
		}
		else if (c == '>') {
			back = pos;
			pos = krust;
			krust = (start[pos] >> 44) ^ back;
		}
		else if (c == '=') {
			neg = false;
			scanf("%lld", &crust);
			if (crust < 0) {
				neg = true;
				krust = -crust;
			}
			else
				krust = crust;
			start[pos] = neg | krust << 1 | ((krust^back) << 44);
		}
		else if (c == '-') {
			start[krust] ^= (pos^back) << 44;
			start[back] ^= (pos ^krust) << 44;
			start[pos] = high;
			high = pos;
			pos = krust;
			krust = (start[pos] >> 44) ^ back;
		}
		else if (c == '!') {
			if (start[pos] & 1) {
				printf("-%llu\n", (start[pos] >> 1) & ((1ull << 43) - 1ull));
			}
			else {
				printf("%llu\n", (start[pos] >> 1) & ((1ull << 43) - 1ull));
			}
		}
		getchar();
	}
	return 0;
}