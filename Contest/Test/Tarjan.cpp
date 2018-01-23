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
#define scanf scanf_s

#endif

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define MAXN 100000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
int N, disc[MAXN], low[MAXN],sccIdx=0;
vector<int> adj[MAXN],scc[MAXN];
stack<int> s;
bool stackMember[MAXN];

void tarjan(int n)
{
	static int time = 0;

	disc[n] = low[n] = ++time;
	s.push(n);
	stackMember[n] = true;

	for (int i : adj[n])
	{
		if (disc[i] == -1)
		{
			tarjan(i);
			low[n] = min(low[n], low[i]);
		}

		else if (stackMember[i] == true)
			low[n] = min(low[n], disc[i]);
	}

	int w = 0;
	if (low[n] == disc[n])
	{
		while (s.top() != n)
		{
			w = (int)s.top();
			scc[sccIdx].push_back(w);
			stackMember[w] = false;
			s.pop();
		}
		w = s.top();
		scc[sccIdx].push_back(w);
		stackMember[w] = false;
		s.pop();
		sccIdx++;
	}
}

void SCC() {
	memset(disc, -1, sizeof disc);
	memset(low, -1, sizeof low);
	/*for (int i = 0; i < N; i++)
		if (disc[i] == -1)
			tarjan(i);*/
	tarjan(0);//Assuming graph is connected 
}

int main()
{
	scan(N);
	return 0;
}