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

const double PI = 3.14159265358979323846;
const double sqrt2 = sqrt(2);

int N;

int main() {
	cin >> N;
	for (int c = 1; c <= N; c++) {
		double a;
		cin >> a;
		if (a > 1.414213) {
			double u = 90;
			double l = 0;
			double m, ca;
			while (true) {
				m = (u + l) / 2;
				ca = cos(m*PI / 180) + sin(m*PI / 180);
				if (abs(ca - a) < 1e-10)
					break;
				if (ca > a)
					u = m;
				else
					l = m;
			}
			printf("Case #%d:\n", c);
			printf("0 0 0.5\n");
			printf("%lf %lf 0\n", cos(m*PI / 180) / 2, sin(m*PI / 180) / 2);
			printf("%lf %lf 0\n", cos((90 + m)*PI / 180) / 2, sin((90 + m)*PI / 180) / 2);
		}
		else {
			double u = 35.237;
			double l = 0;
			double m, ca;
			while (true) {
				m = (u + l) / 2;
				ca = cos(m*PI / 180)*sqrt2 + sin(m*PI / 180);
				if (abs(ca - a) < 1e-10)
					break;
				if (ca > a)
					u = m;
				else
					l = m;
			}
			//z rot = 45 deg
			//x rot = m deg
			double t[][] = { {1 / sqrt2,},{},{},{0,0,0,1} };
		}
	}
	return 0;
}