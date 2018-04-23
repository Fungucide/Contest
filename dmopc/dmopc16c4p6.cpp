// dmopc16c4p6.cpp : Defines the entry polong long for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stack>
#define MAXN 1000006
#define MAXQ 100006

using namespace std;

stack <pair< long long, long long >> s;// Height, Index
long long v[MAXN];
long long psa[MAXN];
int n, q;

int main()
{
	scanf_s("%d %d",&n,&q);
	s.push({ -1,0 });
	int h;
	long long a,b;
	long long maxh = -1;
	for (long long i = 1;i <= n;i++) {
		scanf_s("%d", &h);
		if (h > maxh) {
			maxh = h;
		}
		while (s.top().first > h) {
			a = s.top().first;
			b = s.top().second;
			s.pop();
			v[a] += (b-s.top().second)*(i-b);
		}
		s.push({ h,i });
	}
	while (s.size()!=1) {
		a = s.top().first;
		b = s.top().second;
		s.pop();
		v[a] += (b - s.top().second)*(n+1 - b);
	}
	for (long long i = 1; i <=MAXN;i++) {
		psa[i] = psa[i - 1]+v[i];
	}
	for (long long i = 0; i < q;i++) {
		scanf_s("%lld %lld", &a, &b);
		if (b > maxh) {
			printf("Something");
		}
		printf("%lld\n",psa[b]-psa[a-1]);
	}
    return 0;
}

