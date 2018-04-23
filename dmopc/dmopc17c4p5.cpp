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
#define MAXN 1000000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

ll N;
bool ans[MAXN][4];
ll bestScore = 0;
int idx = -1;

int main() {
	scan(N);
	char c;
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < N; i++) {
			c = getchar();
			ans[i][j] = c == 'T';
		}
		getchar();
	}

	for (int i = 0; i < 4; i++) {
		ll totalScore = 0;
		for (int j = 0; j < 4; j++) {
			if (i == j) {
				totalScore += N * N;
				continue;
			}
			int curScore = 0;
			for (int k = 0; k < N; k++) {
				if (ans[k][j] == ans[k][i])
					curScore++;
				else
					curScore--;
			}
			totalScore += curScore * curScore;
		}
		if (totalScore > bestScore) {
			idx = i;
			bestScore = totalScore;
		}
	}

	for (int i = 0; i < N; i++) {
		if (ans[i][idx])
			printf("T");
		else
			printf("F");
	}
	return 0;
}