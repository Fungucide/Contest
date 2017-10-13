// Divisibility by 11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

string subtract(string a, string b) {
	string total = "";

	int al = a.length() - 1;
	int bl = b.length() - 1;

	int c = 0;
	while (true) {
		if (al >= 0 && bl >= 0) {
			c += stoi(string(1, a.at(al))) - stoi(string(1, b.at(bl)));
		}
		else if (al >= 0) {
			c += stoi(string(1, a.at(al)));
		}
		else {
			break;
		}

		if (c < 0) {
			total = to_string(c + 10) + total;
			c = -1;
		}
		else {
			total = to_string(c) + total;
			c = 0;
		}

		al--;
		bl--;
	}
	if (total.at(0) == '0' && total.length() > 1) {
		total = total.substr(1);
	}
	return total;
}

int main()
{
	int c;
	string n;
	string on;
	cin >> c;
	for (int i = 0; i < c;i++) {
		cin >> n;
		on = n;
		cout << n << endl;
		while (n.length() > 2) {
			n = subtract(n.substr(0, n.length() - 1), n.substr(n.length() - 1, n.length()));
			cout << n << endl;
		}
		if (stoi(n) % 11 == 0) {
			cout << "The number " << on << " is divisible by 11." << endl;
		}else{
			cout << "The number " << on << " is not divisible by 11." << endl;
		}

	}

	return 0;
}

