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
#define MAXN 105

using namespace std;

int N;
double dis[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lf", &dis[i]);
	}
	sort(dis, dis + N);
	double min = 0;
	for (int i = 1; i < N - 1; i++) {
		double size = ((dis[i + 1]+dis[i]) / 2.0) - ((dis[i] + dis[i - 1]) / 2.0);
		//printf("%.1lf\n", size);
		if (size < min || min == 0.0) {
			min = size;
		}
	}
	printf("%.1lf\n", min);
	return 0;
}