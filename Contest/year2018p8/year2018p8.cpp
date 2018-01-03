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
#include <unordered_set>
#define _CRT_SECURE_NO_WARNINGS

#endif

#define MAXN 100000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long 

using namespace std;

ll R, C, K, Q, snow[53][2003];
bool blocked[53][2003];
queue<pair<int, int>> q;
unordered_set<int> queued;

void add(int x, int y) {
	if (x > 0 && y > 0 && x <= R && y <= C && !blocked[x][y] && queued.find(x * 2003 + y) == queued.end()) {
		q.push({ x,y });
		queued.insert(x * 2003 + y);
	}
}

void update() {
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		int x = p.first;
		int y = p.second;
		queued.erase(x * 2003 + y);
		bool state = true;
		if (x != 1 && !blocked[x - 1][y])
			state = false;
		if (y != 1 && !blocked[x][y - 1])
			state = false;
		if (state) {
			blocked[x][y] = true;
			add(x + 1, y);
			add(x, y + 1);
		}
	}
}

int main() {
	scan(R);scan(C);scan(K);scan(Q);
	int type, a, b, c, d, v;
	for (int i = 0; i < Q;i++) {
		scan(type);scan(a);scan(b);scan(c);scan(d);
		if (type == 1) {
			scan(v);
			for (int x = a;x <= c;x++) {
				for (int y = b;y <= d;y++) {
					snow[x][y] += (ll)v;
					if (snow[x][y] >= K) {
						blocked[x][y] = true;
					}
				}
			}
			for (int x = a;x <= c;x++) {
				for (int y = b;y <= d;y++) {
					if (snow[x][y] >= K&&snow[x][y] - (ll)v < K) {
						add(x + 1, y);
						add(x, y + 1);
					}
				}
			}
		}
		else {
			update();
			if (blocked[c][d])
				printf("no\n");
			else
				printf("yes\n");
		}
	}
	return 0;
}