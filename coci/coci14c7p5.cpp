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
#define MAXN 300002//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, K, arr[MAXN];
double psa[MAXN];

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	double lower = 0;
	double upper = 2000000;

	while (upper - lower > 1e-6) {
		long double target = (upper + lower) / 2;
		for (int i = 1; i <= N; i++) {
			psa[i] = arr[i - 1] - target + psa[i - 1];
		}
		double smallest = 0;
		bool flag = false;
		for (int i = K; i <= N; i++) {
			if (psa[i] >= smallest) {
				flag = true;
				break;
			}
			smallest = smallest > psa[i - K + 1] ? psa[i - K + 1] : smallest;
		}
		if (flag)
			lower = target;
		else
			upper = target;
	}
	printf("%f\n", lower);
	return 0;
}