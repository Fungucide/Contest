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
#define LOGN 20//Vertical size of sparse table
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, table[LOGN][MAXN], log_two[MAXN];

void build(int n) {
	for (int i = 1; i < n; ++i)
		log_two[i] = (i >> (log_two[i - 1] + 1)) ? log_two[i - 1] + 1 : log_two[i - 1];
	for (int i = 1, curr = 2; curr < n; curr <<= 1, ++i)
		for (int j = 0; j + curr <= n; ++j)
			table[i][j] = min(table[i - 1][j], table[i - 1][j + (curr >> 1)]);// Note operator here
}

int  query(int l, int r) {
	if (l > r)
		swap(l, r);
	r++;
	int tmp = log_two[r - l];
	return min(table[tmp][l], table[tmp][r - (1 << tmp)]);// Not operator here
}

int main() {
	scan(N);
	return 0;
}