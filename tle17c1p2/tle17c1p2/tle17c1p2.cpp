// tle17c1p2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int f, n;
unordered_map<string, int> map;
unordered_map<int, int> val;//Distance, value
int dis[10000];

int main()
{
	cin >> f;
	string a;
	int b, c;
	for (int i = 0; i < f;i++) {
		cin >> a;
		cin >> b;
		//cout << a << " " << b << "\n";
		map.insert({ a, b });
	}
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> a;
		cin >> b;
		dis[i] = b;
		val.insert({ b,map.at(a) });
	}
	sort(dis, dis + n);
	if (dis[0] != 0) {
		printf("0");
	}

	int e = val.at(0);
	int idx = 0;
	while (e > 0 && idx + 1 != n) {
		idx++;
		e = e - (dis[idx] - dis[idx - 1]) + val.at(dis[idx]);
	}
	printf("%d", idx+1);
	return 0;
}

