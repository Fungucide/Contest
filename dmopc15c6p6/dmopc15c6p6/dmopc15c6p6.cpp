// dmopc15c6p6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>

using namespace std;

list<int> adj[1500];
bool v[1500];
int nv[1500];
int n, m, k;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		a--;b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int j = 0;j < n;j++) {
		memset(v, 0, sizeof(v));
		memset(nv, -1, sizeof(nv));
		int c = 1;
		nv[j] = 0;
		while (true) {
			int mn = -1;
			int mv = 2000;
			for (int i = 0;i < n;i++) {
				if (!v[i] && nv[i] != -1 && mv > nv[i]) {
					mn = i;
					mv = nv[i];
				}
			}

			if (mn == -1)break;

			v[mn] = true;

			for (int i : adj[mn]) {
				if (!v[i] && nv[i] < nv[mn] + 1) {
					if (nv[i] == -1 && nv[mn] + 1 <= k) {
						c++;
					}
					nv[i] = nv[mn] + 1;
				}
			}
		}

		cout << c << "\n";

	}
	return 0;
}

