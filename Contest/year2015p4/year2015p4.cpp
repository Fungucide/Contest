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
#define scanf scanf_s

#endif

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define MAXN 1002//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

struct cust {
	string ord;
	int a, b;
	cust(int va, int vb, string voper) {
		a = va;
		b = vb;
		ord = voper;
	}
};

int A, B, M;
bool v[MAXN][MAXN];
queue<cust> q;

int main() {
	scan(A); scan(B); scan(M);
	if (M > A&&M > B) {
		printf("Not possible\n");
		return 0;
	}
	int a, b;
	q.push({ 0,0,"" });
	while (!q.empty()) {
		cust c = q.front();
		q.pop();
		a = c.a;
		b = c.b;
		if (v[a][b])
			continue;
		v[a][b] = true;
		if (a == M || b == M) {
			cout << c.ord << "\n";
			return 0;
		}
		if (a != A) {
			q.push(cust(A, b, c.ord + "fill A\n"));
		}
		if (b != B) {
			q.push(cust(a, B ,c.ord + "fill B\n" ));
		}
		if (a != 0) {
			q.push(cust(max(a + b - B, 0), min(b + a, B) ,c.ord + "pour A B\n" ));
		}
		if (b != 0) {
			q.push(cust(min(a + b, A), max(a + b - A, 0) ,c.ord + "pour B A\n" ));
		}
		if (a != 0) {
			q.push(cust(0, b ,c.ord + "chug A\n" ));
		}
		if (b != 0) {
			q.push(cust(a, 0 ,c.ord + "chug B\n" ));
		}
	}
	printf("Not possible\n");
	return 0;
}