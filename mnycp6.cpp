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
#define MAXN 10002//1e5
#define BIT int
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int C, bit[MAXN], num[MAXN];
unordered_map<string, int> loc;
//NOTE: p is inclusive [0,p]
void update(int p, BIT v) {
	p++;
	for (int x = p; x < MAXN; x += x & -x)
		bit[x] += v;
}

BIT query(int p) {
	p++;
	if (p <= 0)
		return 0;
	BIT res = 0;
	for (int x = p; x > 0; x -= x & -x)
		res += bit[x];
	return res;
}

int val(string a) {
	int res = 0;
	for (int i = 0; i < a.length(); i++) {
		res += a[i] - 'a' + 1;
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> C;
	string com, a, b;
	for (int i = 0; i < C; i++) {
		cin >> com;
		if (com == "A") {
			cin >> a;
			if (loc.find(a) != loc.end()) {
				printf("Can't add %s\n", a.c_str());
			}
			num[loc.size()] = val(a);
			update(loc.size(), num[loc.size()]);
			loc[a] = loc.size();
		}
		else if (com == "S") {
			cin >> a >> b;
			update(loc[a], num[loc[b]] - num[loc[a]]);
			update(loc[b], num[loc[a]] - num[loc[b]]);
			auto pa = loc.find(a);
			auto pb = loc.find(b);
			pa->second ^= pb->second;
			pb->second ^= pa->second;
			pa->second ^= pb->second;
			swap(num[loc[a]], num[loc[b]]);
		}
		else if (com == "M") {
			cin >> a >> b;
			if (loc[b] < loc[a])
				swap(a, b);
			int res = query(loc[b]) - query(loc[a]-1);
			printf("%d\n", res);
		}
		else if (com == "R") {
			cin >> a >> b;
			int v = val(b);
			update(loc[a], v - num[loc[a]]);
			int temp = loc[a];
			loc.erase(a);
			loc[b] = temp;
		}
		else {
			printf("%d\n", loc.size());
		}
	}
	return 0;
}