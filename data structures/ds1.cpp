// ds1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#define MAXN 100001
#define ll long long

using namespace std;

ll n, m;
ll bit[MAXN];
int num[MAXN];
ll val[MAXN];

void update(int p, ll v) {
	for (int x = p; x <= n; x += x&-x)
		//example of multidimensional
		//for (int y = p; y <= n; y += y&-y)
		bit[x] += v;
}

ll query(int p) {
	ll res = 0;
	for (int x = p; x > 0; x -= x&-x)
		res += bit[x];
	return res;
}

void update2(int p, ll v) {
	for (int x = p; x <= n; x += x&-x)
		//example of multidimensional
		//for (int y = p; y <= n; y += y&-y)
		val[x] += v;
}

ll query2(int p) {
	ll res = 0;
	for (int x = p; x > 0; x -= x&-x)
		res += val[x];
	return res;
}

int main()
{
	scanf_s("%d %d", &n, &m);
	for (int i = 1; i <= n;i++) {
		int x;
		scanf_s("%d", &x);
		num[i] = x;
		update(i, x);
		update2(x, 1);
	}

	for (int i = 0;i < m;i++) {
		char c;
		scanf_s(" %c", &c);
		if (c == 'C') {
			int a, b;
			scanf_s("%d %d",&a,&b);
			update2(num[a],-1);
			update(a, b-num[a]);
			update2(b, 1);
			num[a] = b;
		}else if (c == 'S') {
			int a, b;
			scanf_s("%d %d", &a, &b);
			printf("%lld\n", query(b) - query(a-1));
		}else if (c == 'Q') {
			int a;
			scanf_s("%d", &a);
			printf("%lld\n", query2(a));
		}
	}
	return 0;
}

