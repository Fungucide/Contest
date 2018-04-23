// mwc15c2p2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#define MAXN 1000000

using namespace std;

int n;
int h[MAXN];
int s[MAXN];
stack<int> six;


int main()
{
	cin >> n;
	h[0] = 0;
	s[0] = 0;
	cout << 0<<" ";
	six.push(0);
	int a;
	cin >> a;
	for (int i = 1; i < n;i++) {
		cin >> a;
		h[i] = a;
		if (a > h[six.top()]) {
			s[a] = s[six.top()] + six.size - 1;
			while (!six.empty())
				six.pop();
			six.push(i);
		}else{
			
		}
	}
    return 0;
}

