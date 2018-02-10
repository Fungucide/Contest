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
#define MAXN 15//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N;

void scan2(int &num) {
	bool n = false;
	register int c;
	num = 0;
	c = getchar();
	if (c == '-') {
		n = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58); c = getchar())
		num = num * 10 + c - 48;
	if (n)
		num *= -1;
}

int main() {
	scan2(N);
	return 0;
}