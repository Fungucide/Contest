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
#define MAXN 100002//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
ll N, P, B, C, M, W, des[MAXN], busNum = 0, busCap, res = 0;
vector<int> dis;
ll t = 0;

int main() {
	scan(N); scan(P); scan(B); scan(C);
	scan(M); scan(W);
	for (int i = 0; i < M; i++) {
		scan(des[i]);
	}
	sort(des, des + M);
	if (W <= B) {
		for (int i = 0; i < M; i++) {
			res += (des[i] - 1)*W;
		}
		printf("%lld\n", res);
		return 0;
	}
	if (C >= M) {
		for (int i = 0; i < M; i++) {
			res += (des[i] - 1)*B;
		}
		printf("%lld\n", res);
		return 0;
	}
	for (int i = 0; i < M; i++) {
		if (dis.size() == 0 || dis[dis.size() - 1] != des[i])
			dis.push_back(i);
	}
	busCap = C;
	for (int i = M - 1; i >= 0; i--) {
		ll bus = (des[i] - 1)*B + busNum * P;
		ll walk = (des[i] - 1)*W;
		if (bus < walk) {
			busCap--;
			if (busCap == 0) {
				busNum++;
				busCap = C;
			}
			res += bus;
		}
		else {
			res += walk;
		}
	}
	printf("%lld\n", res);
	return 0;
}