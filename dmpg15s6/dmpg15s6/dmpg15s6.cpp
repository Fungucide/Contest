// dmpg15s6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <unordered_map>
#include <queue>
#include<iostream>
#include <list>
#include <string>
#define MAXF 500

using namespace std;

unordered_map<string, int> eeyore;
list < pair<int, double> > adj[MAXF];
double v[MAXF];

int main()
{
	int n, m, six;
	cin >> n >> m;
	string buff;
	for (int i = 0;i < n;i++) {
		cin >> buff;
		if (buff == "APPLES") {
			six = i;
		}
		eeyore.insert({ buff, i });
	}
	string stuart, sunny;
	double wart;
	for (int i = 0; i < m;i++) {
		cin >> stuart >> sunny >> wart;
		adj[eeyore.at(stuart)].push_back({ eeyore.at(sunny),wart });
	}
	queue<int> q;
	q.push(six);
	v[six] = 1;
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		for (pair<int, double> p : adj[n]) {
			if (v[p.first] < v[n] * p.second) {
				v[p.first] = v[n] * p.second;
				if (p.first == six&&v[p.first] > (double)1) {
					cout << "YA\n";
					return 0;
				}
				q.push(p.first);
			}
		}
	}
	cout << "NAW\n";
	return 0;
}

