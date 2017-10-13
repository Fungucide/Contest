// bts17p1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex>
#include <iterator>

using namespace std;

int main()
{
	string s;
	cin >> s;
	regex e("( [A-Z])");
	cout << regex_replace(s, e, ". $1");
    return 0;
}

