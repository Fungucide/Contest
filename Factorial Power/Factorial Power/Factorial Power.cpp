// Factorial Power.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	float count;
	for (int h = 0;h < 5;h++) {
		cin >> n;
		count = 0;
		for (int i = 1;i <= n;i++) {
			count += log10(i);
		}
		cout << "The length of " << n << "! is " << ceil(count) << endl;
	}
	return 0;
}