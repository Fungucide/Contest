// dmopc17c1p4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int dp[5001][5001],g[5001],h[5001],q[5001],t[5001];
int N, H;

int f(int pos,int time,int gold) {
	if (pos == 0) {

	}
}

int main()
{
	printf_s("%d%d",&N,&H);
	for (int i = 1;i <= N;i++) {
		scanf("%d%d%d%d", &g[i], &h[i], &q[i], &t[i]);
	}
	printf("%d", f(0, 0, 0));
    return 0;
}

