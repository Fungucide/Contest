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

int a, b, c, d, e, f, small = 1 << 30;

int main() {
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
	small = (a - c)*(a - c) + (b - d)*(b - d);
	small = min(small, (a - e)*(a - e) + (b - f)*(b - f));
	small = min(small, (c - e)*(c - e) + (d - f)*(d - f));
	printf("%d\n", small);
	return 0;
}