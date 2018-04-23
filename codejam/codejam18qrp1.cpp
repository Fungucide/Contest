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
#define scanf scanf_s

#endif

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define MAXN 100000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N;

int f(string seq) {
	int dmg = 0, val = 1;
	for (int i = 0; i < seq.length();i++) {
		if (seq[i] == 'C')
			val <<= 1;
		else
			dmg += val;
	}
	return dmg;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int d;
	string seq;
	for (int c = 1; c <= N; c++) {
		cin >> d >> seq;
		int count = 0;
		bool change = true;
		while (f(seq) > d&&change) {
			change = false;
			for (int i = seq.length() - 1; i >= 1; i--) {
				if (seq[i] == 'S'&&seq[i - 1] == 'C') {
					swap(seq[i], seq[i - 1]);
					change = true;
					break;
				}
			}
			count++;
		}
		if (f(seq) <= d)
			printf("Case #%d: %d\n", c, count);
		else
			printf("Case #%d: IMPOSSIBLE\n",c);
	}
	return 0;
}