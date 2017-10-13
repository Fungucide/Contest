// ccc17s5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <vector>
#include <string.h>
#define MAXN 150001
#define SIZE 400

using namespace std;



int n, m, q, l[MAXN], a[MAXN],b[MAXN],s[MAXN / SIZE], d[MAXN], idx[MAXN],  rightMost[MAXN][SIZE];
vector<int> lIdx[MAXN];

inline int f(int i) {
	return a[lIdx[l[i]][(idx[i] + d[l[i]]) % lIdx[l[i]].size()]];
}

int main() {
	scanf_s("%d%d%d", &n, &m, &q);
	memset(rightMost, -1, sizeof rightMost);
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &l[i]);
		lIdx[l[i]].push_back(i);
		idx[i] = lIdx[l[i]].size() - 1;
		b[i] = i / SIZE;
		rightMost[l[i]][b[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &a[i]);
		s[b[i]] += a[i];
	}
	int a, l, r, x;
	for (int cust = 0; cust < q; cust++) {
		scanf_s("%d", &a);
		if (a == 1) {
			scanf_s("%d%d", &l, &r);
			int res = 0;
			if (r - l < SIZE) {
				for (int i = l; i <= r; i++) {
					res += f(i);
				}
			}
			else {
				while (l % SIZE) {
					res += f(l);
					l++;
				}
				while (l + SIZE <= r) {
					res += s[b[l]];
					l += SIZE;
				}
				while (l <= r) {
					res += f(l);
					l++;
				}
			}
			printf("%d\n", res);
		}
		else {
			scanf_s("%d", &x);
			int first = -1;
			int val = 0;
			for (int i = 0; i < SIZE; i++) {
				int rt = rightMost[x][i];
				if (rt == -1) continue;
				if (first == -1) first = i;
				s[i] += val;
				val = f(rt);
				s[i] -= val;
			}
			s[first] += val;
			d[x] = (d[x] + lIdx[x].size() - 1) % lIdx[x].size();
		}
	}
	return 0;
}