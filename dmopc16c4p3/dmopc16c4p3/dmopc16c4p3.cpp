// dmopc16c4p3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <set>
#include <list>

using namespace std;

int dis[100000];
set<pair<int, int> > candy[102];// [Candy Num] + Dis, Shop Num and sort
list<int> shop[100000];
int n, s;

int main()
{
	scanf_s("%d %d", &n, &s);
	for (int i = 0; i < n;i++) {
		scanf_s("%d", &dis[i]);
	}
	int a, b;
	for (int i = 0; i < s;i++) {
		scanf_s("%d %d", &a, &b);
		candy[b].insert({ dis[--a],a });
	}
	int q;
	scanf_s("%d", &q);
	for (int i = 0;i < q;i++) {
		char c;
		scanf_s(" %c", &c);
		if (c == 'A') {
			scanf_s("%d %d", &a, &b);
			candy[b].insert({ dis[--a], a });
		}
		else if (c == 'S') {
			scanf_s("%d %d", &a, &b);
			candy[b].erase({ dis[--a],a });
		}
		else if (c == 'E') {
			scanf_s("%d %d", &a, &b);
			--a;
			for (int j = 0;j < 102;j++) {
				if (candy[j].find({ dis[a],a }) == candy[j].end());
				candy[j].erase({ dis[a],a });
			}
			dis[a] = b;
		}
		else if (c == 'Q') {
			scanf_s("%d", &a);
			if (candy[a].empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", (*candy[a].begin()).second + 1);
			}
		}
	}
	return 0;
}

