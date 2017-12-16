// dmopc17c1p1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#define MAXN 1001

bool x[MAXN], y[MAXN];
int c,r,q;

using namespace std;

int main()
{
	scanf_s("%d%d",&r,&c);
	string s;
	for (int i = 0; i < r;i++) {
		scanf_s(" %s", &s);
		for (int j = 0;j < c;j++) {
			if (s[j] == 'X') {
				x[j] = true;
				y[i] = true;
			}
		}
	}
	scanf_s("%d", &q);
	int a, b;
	for (int i = 0; i < q;i++) {
		scanf_s("%d%d", &a, &b);
		if (x[a] || y[b]) {
			printf("Y");
		}
		else {
			printf("N");
		}
	}
    return 0;
}

