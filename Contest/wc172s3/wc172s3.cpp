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
#include <set>
#define scanf scanf_s

#endif

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define MAXN 100000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

struct cust {
	bool operator()(const pii &l, const pii &r) {
		return l.first < r.first;
	}
};

int N;
set<int> archer;//Begin - End
set<int> orc;//Location


int main() {
	scan(N);
	int cmd, loc, range;
	for (int i = 0; i < N; i++) {
		scan(cmd); scan(loc);
		if (cmd == 2) {
			scan(range);
			archer.insert(loc+1);
			archer.insert(loc - 1);
			//Find what range to delete
			auto start = orc.upper_bound(loc - range - 1);
			auto finish = orc.lower_bound(loc + range + 1);
			orc.erase(start, finish);
		}
		else {
			if(archer.find(loc)==archer.end())
				orc.insert(loc);
		}
		printf("%d\n", orc.size());
	}
	return 0;
}