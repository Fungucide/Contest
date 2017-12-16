// mmcc14p2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#define MAXN 2001
#define MAXM 5001

using namespace std;

int bit[MAXN][MAXM];
int n, m;

void update(int a, int b, int v) {
	for (int x = a; x <= n; x += x&-x)
		for (int y = b; y <= m; y += y&-y)
			bit[x][y] += v;
}

int query(int a, int b) {
	int res = 0;
	for (int x = a; x > 0; x -= x&-x)
		for (int y = b; y > 0; y -= y&-y)
			res += bit[x][y];
	return res;
}

int rquery(int a, int b, int x, int y) {
	int res = 0;
	res += query(x, y) + query(a, b);
	res -= query(a, y) + query(x, b);
	return res;
}

int main()
{

	cin >> n >> m;
	string s;
	for (int y = 1; y < m;y++) {
		cin >> s;
		for (int x = 0; x < n;x++) {
			update(x, y, s[x] - '0');
		}
	}
	return 0;
}

int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  build();
  modify(0, 1);
  printf("%d\n", query(3, 11));
  return 0;
}
