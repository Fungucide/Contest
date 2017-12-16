// dwitesep09p1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool isSuper(int n) {
	int sum = 0;
	for (int i = 0; i < to_string(n).length();i++) {
		sum += (n % (int)pow(10, i + 1) - n % (int)pow(10, i)) / pow(10, i);
	}
	return sum % 2 == 0;
}

bool isSpecial(int n) {
	int pNumb = -1;
	for (int i = 0; i < to_string(n).length();i++) {
		if (pNumb >= (n % (int)pow(10, i + 1) - n % (int)pow(10, i)) / pow(10, i)) {
			return false;
		}
		pNumb = (n % (int)pow(10, i + 1) - n % (int)pow(10, i)) / pow(10, i);
	}
	return true;
}

bool isAwsome(int n) {
	int i = 2;
	for (;i*i <= n;i++) {
		if (n % (i*i) == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	int a;
	int b;
	int count;
	for (int i = 0; i < 5;i++) {
		cin >> a;
		cin >> b;
		count = 0;
		for (int h = a; h <= b;h++) {
			if (isSuper(h)&&isSpecial(h)&&isAwsome(h)) {
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}

