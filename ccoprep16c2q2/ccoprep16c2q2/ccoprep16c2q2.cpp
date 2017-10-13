// ccoprep16c2q2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{	
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int c = 0;
	int j;
	for (int i = 0; i < n;i++) {
		cin >> j;
		c += j & 1;
	}
	cout << c << endl;
    return 0;
}

