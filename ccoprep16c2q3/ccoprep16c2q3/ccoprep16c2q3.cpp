// ccoprep16c2q3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#define MAXN 200001

using namespace std;

int n, q, s;
int p[MAXN], nxt[MAXN], hop[MAXN], block[MAXN];

int main()
{
	scanf_s("%d", &n);
	for (int i = 0; i < n;i++) {
		scanf_s("%d", &p[i]);
	}
	s = sqrt(n);
	for (int i = 0;i < n;i++)
		block[i] = i / s;

	for (int i = n - 1;i >= 0;i--) {
		if (block[i + p[i]] != block[i]) {
			nxt[i] = i + p[i];
			hop[i] = 1;
		}
		else {
			nxt[i] = nxt[i + p[i]];
			hop[i] = hop[i + p[i]] + 1;
		}
	}

	scanf_s("%d", &q);
	int a, b, c;
	for (int i = 0;i < q;i++) {
		scanf_s("%d", &a);
		if (a == 1) {
			scanf_s("%d", &b);
			c = 0;
			while (b < n) {
				c += hop[b];
				b = nxt[b];
			}
			printf("%d\n", c);
		}
		else {
			scanf_s("%d %d", &b, &c);
			p[b] = c;
			for (int j = b;j >= 0 && block[j] == block[b];j--) {
				if (block[j + p[j]] != block[j]) {
					nxt[j] = j + p[j];
					hop[j] = 1;
				}
				else {
					nxt[j] = nxt[j + p[j]];
					hop[j] = hop[j + p[j]] + 1;
				}
			}
		}
	}

	return 0;
}

