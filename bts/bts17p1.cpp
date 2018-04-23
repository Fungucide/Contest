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

