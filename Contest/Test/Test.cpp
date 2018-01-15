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

int bs(vector<int> val, int num) {//Higher
	int idx, lb = -1, hb = val.size();
	while (hb - lb > 1) {
		idx = (lb + hb) >> 1;
		if (val[idx] > num)
			hb = idx;
		else if (val[idx] < num)
			lb = idx;
		else if (val[idx] == num)
			hb = idx, lb = idx;
	}
	return val[hb];
}

int main() {
	for (int i = 1; i < 21;i++)
		printf("%d -> %d\n", i, bs({ 1,3,6,9,20 }, i));
	return 0;
}