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
#include <regex>
#define scanf scanf_s

#endif

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define MAXN 100000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

ll start, high, front,idx;
//ll prime[455052552];
regex p(".?|(..+?)\\1+");

int main() {
	scan(start);scan(high);
	//prime[0] = 2;
	//prime[1] = 3;
	idx = 2;
	for (ll i = 1;i <= high;i++) {
		if (regex_match(new char[i], p)) {
			printf("%lld\n", i);
		}
	}
	return 0;
}