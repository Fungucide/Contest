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
#define MAXN 105

using namespace std;

int N, info[MAXN][MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &info[i][j]);//Row , Col
		}
	}

	//If normal
	bool xFlip = info[0][0] > info[0][1];
	bool yFlip = info[0][0] > info[1][0];
	if (info[0][0] < info[0][1] && info[0][0] < info[1][0]) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				printf("%d ", info[i][j]);
			}
			printf("\n");
		}
	}
	else if (info[0][N - 1] < info[0][N - 2] && info[0][N - 1] < info[1][N - 1]) {
		for (int i = N-1; i >=0; i--) {
			for (int j = 0; j <N; j++) {
				printf("%d ", info[j][i]);
			}
			printf("\n");
		}
	}
	else if (info[N - 1][0] < info[N - 2][0] && info[N - 1][0] < info[N - 1][1]) {
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				printf("%d ", info[j][i]);
			}
			printf("\n");
		}
	}
	else {
		for (int i = N - 1; i >= 0; i--) {
			for (int j = N - 1; j >= 0; j--) {
				printf("%d ", info[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}