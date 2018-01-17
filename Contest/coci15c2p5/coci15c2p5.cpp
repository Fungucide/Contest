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
#define MAXN 1000003
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define BIT int

using namespace std;

int N, bit[MAXN], val[MAXN], sum[MAXN], psa[MAXN], average;
unordered_map<int, int> start;
//NOTE: p is inclusive [0,p]
void update(int p, BIT v) {
	p++;
	for (int x = p; x < MAXN; x += x&-x)
		bit[x] += v;
}

BIT query(int p) {
	p++;
	BIT res = 0;
	for (int x = p; x > 0; x -= x&-x)
		res += bit[x];
	return res;
}

int main() {
	scan(N);
	for (int i = 0; i < N; i++) {
		scan(val[i]);
	}
	scan(average);
	for (int i = 0; i < N; i++) {
		val[i] -= average;
		psa[i] += val[i];
		if (i != 0)
			psa[i] += psa[i - 1];
		sum[i] = psa[i];
	}
	sort(psa, psa + N + 1);
	for (int i = 0; i <= N; i++) {
		if (start.find(psa[i]) == start.end())
			start[psa[i]] = start.size();
	}

	ll res = 0;
	update(start[0],1);
	for (int i = 0; i < N; i++) {
		res += (ll)(query(start[sum[i]]));
		update(start[sum[i]], 1);
	}
	printf("%lld\n", res);
	return 0;
}