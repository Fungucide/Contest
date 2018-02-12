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
#define MAXN 11//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, M, C[MAXN], need[MAXN], deal[101][12],has[MAXN];

int main() {
	scan(N); scan(M);
	for (int i = 0; i < N; i++)
		scan(C[i]);
	for (int i = 0; i < M; i++) {
		scan(deal[i][11]);
		for (int j = 0; j < N; j++) {
			scan(deal[i][j]);
		}
	}
	int orgCost = 0;
	for (int i = 0; i < N; i++) {
		scan(need[i]);
		orgCost += need[i] * C[i];
	}
	int res = orgCost;
	for (int i = 0; i < 1 << M; i++) {
		memset(has, 0, sizeof has);
		int nCost = orgCost;

		for (int j = 0; j < M; j++) {
			bool flag = true;
			//Bitcust
			if (i & 1 << j) {
				//Check to make sure not over
				for (int k = 0; k < N; k++) {
					//Cust the check
					if (has[k] + deal[j][k] > need[k]) {
						flag = false;
						break;
					}

				}
				//If not over
				if (flag) {
					nCost += deal[j][11];
					//Add the cust
					for (int k = 0; k < N; k++) {
						has[k] += deal[j][k];
						nCost -= deal[j][k] * C[k];
					}
				}

			}
		}

		if (nCost < res)
			res = nCost;
	}
	printf("%d\n", res);
	return 0;
}