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

int N, M;
vector<int> A, B;

int main() {
	scan(N); scan(M);
	if (N == 0) {
		printf("0 %d\n", M);
		return 0;
	}
	else if (M == 0) {
		printf("%d 0\n", N);
		return 0;
	}
	int a;
	for (int i = 0; i < N; i++) {
		scan(a);
		A.push_back(a);
	}
	for (int i = 0; i < M; i++) {
		scan(a);
		B.push_back(a);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	if (A[0] < B[0]) {
		for (int i = 0; i < N; i++) {
			if (A[i] > B[0]) {
				printf("%d 0\n", i);
				return 0;
			}
		}
		printf("%d 0\n", N);
		return 0;
	}
	for (int i = 0; i < M; i++) {
		if (B[i] > A[0]) {
			printf("0 %d\n", i);
			return 0;
		}
	}
	printf("0 %d\n", M);
	return 0;
}