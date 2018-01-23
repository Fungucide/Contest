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
#define MAXN 500000//1e5
#define MOD 1000000007
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
int N, M, disc[MAXN], low[MAXN], sccIdx = 0, val[MAXN], sccVal[MAXN], scc[MAXN];
pii dp[MAXN][2];
vector<int> adj[MAXN], dag[MAXN];
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
			scc[w] = sccIdx;
			sccVal[sccIdx] += val[w];
			stackMember[w] = false;
			s.pop();
		}
		w = s.top();
		scc[w] = sccIdx;
		sccVal[sccIdx] += val[w];
		stackMember[w] = false;
		s.pop();
		sccIdx++;
	}
}

void SCC() {
	memset(disc, -1, sizeof disc);
	memset(low, -1, sizeof low);
	for (int i = 0; i < N; i++)
		if (disc[i] == -1)
			tarjan(i);
	//tarjan(0);//Assuming graph is connected 
	for (int i = 0; i < N; i++) {
		for (int e : adj[i]) {
			if (scc[i] != scc[e])
				dag[scc[i]].push_back(scc[e]);
		}
	}
}

pii f(int idx, int c) {
	if (idx == scc[N - 1])
		return c ? pii{ sccVal[idx], 1 } : pii{ 0, 1 };
	if (dp[idx][c] == pii{ -1,-1 }) {
		pii max = { -1,0 };
		pii temp;
		for (int i : dag[idx]) {
			if (c) {
				temp = f(i, 0);
				temp.first += sccVal[idx];
				if (temp.first > max.first)
					max = temp;
				else if (temp.first == max.first)
					max.second = (max.second + temp.second) % MOD;
			}
			temp = f(i, 1);
			if (temp.first > max.first)
				max = temp;
			else if (temp.first == max.first)
				max.second = (max.second + temp.second) % MOD;
		}
		dp[idx][c] = max;
	}
	return dp[idx][c];
}

int main()
{
	memset(scc, -1, sizeof scc);
	scan(N); scan(M);
	for (int i = 0; i < N; i++)
		scan(val[i]);
	int a, b;
	for (int i = 0; i < M; i++) {
		scan(a); scan(b);
		adj[--a].push_back(--b);
	}
	SCC();
	for (int i = 0; i < sccIdx; i++) {
		dp[i][0] = { -1,-1 };
		dp[i][1] = { -1,-1 };
	}

	pii res = f(scc[0], 1);
	printf("%d %d\n", res.first, res.second);
	return 0;
}
