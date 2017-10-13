// bts17p6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <unordered_map>
#define MAXN 100006

using namespace std;

unordered_map<int, int> map;
int n, order[MAXN], bit[MAXN];

void update(int p, int v) {
	for (int x = p; x <= n; x += x&-x)
		//example of multidimensional
		//for (int y = p; y <= n; y += y&-y)
		bit[x] += v;
}

int query(int p) {
	int res = 0;
	for (int x = p; x > 0; x -= x&-x)
		res += bit[x];
	return res;
}

int main()
{
	scanf_s("%d", &n);
	int a;
	for (int i = 1; i <= n;i++) {
		update(i,1);
		scanf_s("%d", &a);
		map[a] = i;
	}
	for (int i = 1;i <= n;i++) {
		scanf_s("%d", &a);
		order[i] = map[a];
	}

	int cur = 1,start=-1, end = -1, length = 0;

	for (int i = 1;i <= n;i++) {
		if (order[i - 1] < order[i]) {
			if (i - cur + 1 > length) {
				length = i - cur + 1;
				start = cur;
				end = i;
			}
		}
		else {
			cur = i;
		}
	}

	printf("%d\n", n - length);
	int f = 0;
	for (int i = start - 1;i > 0;i--) {
		printf("F %d\n",query(order[i])+f);
		f++;
		update(order[i], -1);
	}
	for (int i = end + 1;i <= n;i++) {
		printf("B %d\n",query(order[i]) + f);
		update(order[i], -1);
	}

	return 0;
}

