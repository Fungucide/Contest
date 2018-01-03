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
#define _CRT_SECURE_NO_WARNINGS 1

#endif

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long

using namespace std;

ll H, M, S;
ll t, VAL = 12 * 3600;

int main() {
	scanf("%lld%lld%lld", &H, &M, &S);
	H %= 12;
	M %= 12 * 60;
	S %= 12 * 3600;
	t = (H * 3600) % VAL + (M * 60) % VAL + S;
	t %= VAL;
	t = VAL - t;
	if (t / 3600 == 12)
		printf("00:");
	else
		printf("%02lld:", t / 3600ll);
	t %= 3600;
	printf("%02lld:", t / 60ll);
	t %= 60;
	printf("%02lld\n", t);
	return 0;
}