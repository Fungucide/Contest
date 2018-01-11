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

ll N, kust = 2, pos = 1, front = 0, back = 0;
ull cust[1000001];//[0,0] bit = Neg or not Next  [1,41] Bits Number [42,61]

int main() {
	scan(N);
	char c;
	ll a;
	ll crust;
	bool neg = false;
	for (int i = 2; i < 999999; i++) {
		cust[i] = i + 1;
	}
	for (int i = 0; i < N; i++) {
		c = getchar();
		if (c == '+') {
			neg = false;
			scanf("%lld", &crust);
			if (crust < 0) {
				neg = true;
				crust = -crust;
			}
			a = kust;
			kust = cust[kust];
			cust[a] = crust << 1ll | neg | ((pos^back) << 42ll);
			cust[pos] ^= (back << 42ll) ^ (a << 42ll);
			cust[back] ^= (pos << 42ll) ^ (a << 42ll);
			front = pos;
			pos = a;
		}
		else if (c == '<') {
			front = pos;
			pos = back;
			back = (cust[pos] >> 42ll) ^ front;
		}
		else if (c == '>') {
			back = pos;
			pos = front;
			front = (cust[pos] >> 42ll) ^ back;
		}
		else if (c == '=') {
			neg = false;
			scanf("%d", &crust);
			if (crust < 0) {
				neg = true;
				crust = -crust;
			}
			cust[pos] = neg | crust << 1ll | ((cust[pos] >> 42ll) << 42ll);
		}
		else if (c == '-') {
			cust[front] ^= (pos << 42ll) ^ (back << 42ll);
			cust[back] ^= (pos << 42ll) ^ (front << 42ll);
			cust[pos] = kust;
			kust = pos;
			pos = front;
			front = (cust[pos] >> 42ll) ^ back;
		}
		else if (c == '!') {
			if (cust[pos] & 1) {
				printf("-%lld\n", ((cust[pos] & ((1ll << 42ll) - 1ll))) >> 1ll);
			}
			else {
				printf("%lld\n", ((cust[pos] & ((1ll << 42ll) - 1ll))) >> 1ll);
			}
		}
		getchar();
	}
	return 0;
}