// A plus B two.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

string add(string a, string b) {
	string total = "";

	int al = a.length() - 1;
	int bl = b.length() - 1;

	int c = 0;
	while (true) {
		if (al >= 0 && bl >= 0) {
			c += stoi(string(1, a.at(al))) + stoi(string(1, b.at(bl)));
		}
		else if (al >= 0) {
			c += stoi(string(1, a.at(al)));
		}
		else if (bl >= 0) {
			c += stoi(string(1, b.at(bl)));
		}
		else {
			break;
		}

		if (c > 9) {
			total = to_string(c - 10) + total;
			c = 1;
		}
		else {
			total = to_string(c) + total;
			c = 0;
		}

		al--;
		bl--;
	}
	if (c == 1) {
		total = "1" + total;
	}
	return total;
}

string subtract(string a, string b) {
	string total = "";
	string temp;
	bool negative = false;
	if (a.length() < b.length()) {
		negative = true;
		temp = a;
		a = b;
		b = temp;
	}
	else if (a < b && a.length() == b.length()) {
		negative = true;
		temp = a;
		a = b;
		b = temp;
	}

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
	if (negative) {
		total = "-" + total;
	}
	return total;
}



int main()
{
	int n;
	string a;
	string b;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> a;
		cin >> b;

		if (a.at(0) == '-' && b.at(0) == '-') {
			cout << "-" << add(a.substr(1), b.substr(1)) << endl;
		}
		else if (b.at(0) == '-') {
			cout << subtract(a, b.substr(1)) << endl;
		}
		else if (a.at(0) == '-') {
			cout << subtract(b, a.substr(1)) << endl;
		}
		else {
			cout << add(a, b) << endl;
		}
	}
	return 0;
}

