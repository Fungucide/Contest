// thicc17p6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <unordered_map>
#include <cstring>
#include <string>
#define MAXN 200000

using namespace std;

int w[MAXN];
int mi1 = 0;
int mi2 = 0;
int mw1 = -1;
int mw2 = -2;
list<pair<int, int>> adj[MAXN];
int con[MAXN];

int main()
{
	int n, t;
	ios::sync_with_stdio(false);
	cin >> n >> t;
	for (int i = 1;i < n;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
		con[a]++;
		con[b]++;
	}
	list<int> q;
	q.push_back(0);
	int no;
	while (!q.empty()) {
		no = q.front();
		q.pop_front();
		bool flag = false;
		for (pair<int, int> t : adj[no]) {
			flag = true;
			w[t.first] = w[no] + t.second;
			q.push_back(t.first);
		}
		if (!flag) {
			if (w[no] > mw1) {
				mw2 = mw1;
				mi2 = mi1;
				mw1 = w[no];
				mi1 = no;
			}
			else if (w[no] > mw2) {
				mw2 = w[no];
				mi2 = no;
			}
		}
	}
	for()

	return 0;
}

