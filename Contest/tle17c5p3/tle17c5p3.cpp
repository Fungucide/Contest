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
#define MAXN 205//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N;
bool isUnit[MAXN];

int main() {
	scan(N);
	printf("Units:\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((i*j) % N == 1) {
				printf("%d\n", i);
				isUnit[i] = true;
				break;
			}
		}
	}
	printf("Irreducibles:\n");
	for (int i = 0; i < N; i++) {
		if (isUnit[i])
			continue;
		bool flag = true;
		for (int a = 1; a < N&&flag; a++) {
			if (isUnit[a])
				continue;
			for (int b = 0; b < N; b++) {
				if (isUnit[b])
					continue;
				if ((a*b) % N == i) {
					flag = false;
					break;
				}
			}
		}
		if (flag)
			printf("%d\n", i);
	}
	printf("Primes:\n");
	for (int p = 1; p < N; p++) {
		if (isUnit[p])
			continue;
		bool cust = true;
		for (int a = 0; a < N&&cust; a++) {
			for (int b = 0; b < N&&cust; b++) {
				bool flag = false;

				for (int x = 0; x < N && !flag; x++) {
					if ((p*x) % N == (a*b) % N) {
						flag = true;
						break;
					}
				}
				if (!flag)
					continue;
				flag = false;
				for (int y = 0; y < N; y++) {
					if ((p*y) % N == a || (p*y) % N == b) {
						flag = true;
						break;
					}
				}
				if (!flag) {
					cust = false;
				}

			}
		}
		if (cust)
			printf("%d\n", p);
	}
	return 0;
}