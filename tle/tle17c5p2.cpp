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

int N, D, dis[MAXN], start = 1 << 30, turn = -1 << 30, finish = 1 << 30, start2 = -1 << 30, turn2 = 1 << 30, finish2 = -1 << 30;

int main() {
	scan(N); scan(D);
	for (int i = 0; i < N; i++)
		scanf("%d", &dis[i]);
	int a, b;
	for (int i = 0; i < D; i++) {
		scan(a); scan(b);
		a = dis[a - 1]; b = dis[b - 1];
		if (a < b) {
			start = min(start, a);
			turn = max(turn, b);
			finish2 = max(finish2, b);
			turn2 = min(turn2, a);
		}
		else {
			finish = min(finish, b);
			turn = max(turn, a);
			start2 = max(start2, a);
			turn2 = min(turn2, b);
		}
	}
	if (start == 1 << 30)
		start = turn;
	if (finish == 1 << 30)
		finish = turn;
	if (start2 == -1 << 30)
		start2 = turn2;
	if (finish2 == -1 << 30)
		finish2 = turn2;
	printf("%d\n", min((turn << 1) - start - finish, abs((turn2 << 1) - start2 - finish2)));
	return 0;
}