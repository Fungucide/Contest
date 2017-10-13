// dmopc13c3p5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#define MAX(A,B)(A>B?A:B)

using namespace std;
struct six {
	int v, t, f;
};
int m, u, r;
six rest[150];
int dp[151][301][101];
int f(int a, int b, int c) {
	int &res = dp[a][b][c];
	if (res == -1) {
		if (a == r) {
			res = 0;
		}
		else {
			res = f(a + 1, b, c);
			if (b + rest[a].t <= m && c + rest[a].f <= u) {
				res = MAX(f(a + 1, b + rest[a].t, c + rest[a].f) + rest[a].v, res);
				//cout << rest[a].v << endl;
			}
		}
	}
	//cout << m << endl;
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	cin >> m >> u >> r;
	for (int i = 0;i < r;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		rest[i] = { a,b,c };
	}
	cout << f(0, 0, 0)<<"\n";
	return 0;
}
