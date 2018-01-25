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
#define MAXN 7//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, start, finish;
bool v[1 << (MAXN * 3) + 1];
queue<pii> q;

void clear() {
	queue<pii> c;
	swap(q, c);
}

int main() {
	while (1) {
		scan(N);
		if (N == 0)
			return 0;
		int a;
		start = 0;
		finish = 0;
		for (int i = 0; i < N; i++) {
			scan(a);
			start |= i << (--a * 3);
			finish |= i << (i * 3);
		}
		memset(v, false, sizeof v);
		q.push({ start,0 });
		int state, depth;
		while (!q.empty()) {
			state = q.front().first;
			depth = q.front().second;
			q.pop();
			if (state == finish) {
				v[state] = true;
				printf("%d\n", depth);
				clear();
				break;
			}
			if (v[state])
				continue;
			int loc, cloc, clear;
			bool l, r;
			for (int i = 0; i < N; i++) {
				loc = (state >> (i * 3)) & 7;
				clear = state & ~(7 << (i * 3));
				l = r = true;
				for (int j = 0; j < i; j++) {
					cloc = (state >> (j * 3)) & 7;
					if (cloc + 1 == loc)
						l = false;
					if (cloc == loc)
						r = l = false;
					if (cloc - 1 == loc)
						r = false;
				}
				if (loc > 0 && l)
					q.push({ clear | ((loc - 1) << (i * 3)) ,depth + 1 });
				if (loc + 1 < N && r)
					q.push({ clear | ((loc + 1) << (i * 3)) ,depth + 1 });
			}
			v[state] = true;
		}
		if (!v[finish])
			printf("IMPOSSIBLE\n");
	}

}