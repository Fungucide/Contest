// dmopc17c1p2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#define MAXN 1000002
#define ll long long

ll psa[MAXN];
ll n, m;

int main()
{	
	scanf_s("%ld%ld",&n,&m);
	psa[0] = 0;
	for (int i = 0; i < n;i++) {
		scanf_s("%ld", &psa[i + 1]);
		psa[i + 1] += psa[i];
	}
	ll count = 0;
	for (int i = 0; i < n;i++) {
		for (int j = i + 1;j <= n;j++) {
			if ((psa[j] - psa[i]) % m == 0) {
				++count;
			}
		}
	}
	printf("%ld\n", count);
    return 0;
}

