// ccc14s5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <math.h>
#define MAX(X,Y)(X>Y?X:Y)
#define MAXV 2001

using namespace std;

int dp[MAXV][MAXV];
double dis[MAXV][MAXV];
vector<pair<double, double>> t;
int n;

double g(int x, int y) {
	if (dis[x][y] == -1) {
		double a = t.at(x).first;
		double b = t.at(x).second;
		double c = t.at(y).first;
		double d = t.at(y).second;
		dis[x][y] = sqrt((a - c)*(a - c) + (b - d)*(b - d));
		dis[y][x] = dis[x][y];
	}
	return dis[x][y];
}

int f(int x, int c) {
	if (dp[x][c] == -1) {
		double ldis;
		if (x != 0) {
			ldis = g(x, c);
		}
		else {
			ldis = 20000;
		}
		int	max = 1;
		for (int i = 1; i < n;i++) {
			if (i != x && ldis > g(x, i)) {
				max = MAX(max, f(i, x) + 1);
			}
		}
		dp[x][c] = max;
	}
	return dp[x][c];
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf_s("%d", &n);
	for (int i = 0;i <= n;i++) {
		for (int j = 0; j <= n;j++) {
			dis[j][i] = -1;
		}
	}
	t.push_back({ 0,0 });
	for (int i = 0;i < n;i++) {
		double a, b;
		scanf_s("%lf %lf", &a, &b);
		t.push_back({ a,b });
	}
	printf("%d\n", f(0, 0));
	return 0;
}

