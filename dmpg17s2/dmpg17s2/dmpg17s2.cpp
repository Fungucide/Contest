// dmpg17s2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int djset[100000];

int find(int n) {
	if (djset[n] != n) {
		djset[n] = find(djset[n]);
	}
	return djset[n];
}

void merge(int x, int y) {
	djset[find(x)] = djset[find(y)];
}

int main()
{
	int n, q;
	cin >> n >> q;
	for (int i = 0;i < n;i++) {
		djset[i] = i;
	}
	for (int i = 0;i < q;i++) {
		char a;
		int b, c;
		cin >> a >> b >> c;
		b--;
		c--;
		if (a == 'A') {
			merge(b, c);
		}
		else {
			if ( find(b)==find(c)) {
				cout << "Y" << endl;
			}
			else {
				cout << "N" << endl;
			}
		}
	}
	return 0;
}

