#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#define scanf scanf_s

#endif

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define MAXN 100000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N;

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

int main() {
	scan(N);
	char c;
	string cur = "0";
	string total = "0";
	for (int i = 0; i < N; i++) {
		c = getchar();
		if (c != '-') {
			total = add(total, cur + c);
			cur += c;
		}
		else {
			total = add(total, cur.substr(0, cur.length() - 1));
			cur = cur.substr(0, cur.length() - 1);
		}
	}
	cout << total << "\n";
	return 0;
}