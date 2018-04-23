// tle17c1p1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <String>

using namespace std;

int main()
{
	string s;
	cin >> s;
	bool roun = true;
	bool add = false;
	for (int i = s.length() - 1;i >= 0;i--) {
		//cout << s[i] << endl;
		if (roun) {
			roun = false;
			if ('n' <= s[i] && s[i] <= 'z') {
				add = true;
				s[i] = 'a';
			}
			else {
				s[i] = 'a';
				break;
			}
		}
		else if (add) {
			add = false;
			if (s[i] == 'z') {
				roun = true;
				i++;
				continue;
			}
			else {
				s[i] += 1;
			}
		}
	}
	if (add) {
		s = "a" + s;
	}
	cout << s << "\n";
	return 0;
}

