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
#include <list>
#include <stack>
#include <set>
#define scanf scanf_s

#endif

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define MAXN 100000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

struct node {
	string p;
	int x, y;
};

string dir[4], path;
int cor[4][2] = { {0,1},{0,-1},{1,0},{-1,0} },res=0;
bool v[5001][5001];
queue<node> q;

int main() {
	cin >> dir[0] >> dir[1] >> dir[2] >> dir[3] >> path;
	//scanf("%s%s%s%s%s", &dir[0], &dir[1], &dir[2], &dir[3],&path);

	q.push({ path,2500,2500 });

	while (!q.empty()) {
		node p = q.front();
		q.pop();
		if (p.p.length() == 0) {
			if (!v[p.x][p.y]) {
				v[p.x][p.y] = true;
				res++;
			}
			continue;
		}
		for(int i = 0 ; i<4;i++){
			if (p.p.length()>=dir[i].length()&&p.p.compare(0,dir[i].length(),dir[i])==0) {
				q.push({ p.p.substr(dir[i].length()),p.x + cor[i][0],p.y + cor[i][1]});
			}
		}
	}

	printf("%d\n", res);

	return 0;
}