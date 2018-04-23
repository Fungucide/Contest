// cco13p2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#define MAXN 2<<20

using namespace std;

int bit[MAXN],s[MAXN];
int n, m;

void update(int p, int v) {
	for (int x = p; x <= n; x += x&-x)
		bit[x] += v;
}

int query(int p) {
	int res = 0;
	for (int x = p; x > 0; x -= x&-x)
		res += bit[x];
	return res;
}

int main()
{
	cin >> n >> m;
	int a;
	for (int i = 0; i < 2 << n;i++) {
		cin >> a;
		s[i] = a;

	}
    return 0;
}

