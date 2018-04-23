#include <stdio.h>
#include <vector>
#include <queue>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 200001

using namespace std;

int N, K, c[MAXN], nOfC[MAXN];
vector<int> adj[MAXN];
bool vis1[MAXN], vis2[MAXN], inactive[MAXN];

int main() {
	scan(N);scan(K);
	for (int i = 0; i < N;i++) {
		scan(c[i+1]);
	}
	int a, b;
	for (int i = 1;i < N;i++) {
		scan(a);scan(b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		nOfC[a]++;
		nOfC[b]++;
	}
	queue<pair<int, int>> bfs1;
	int md = 1;
	int node1 = 1;
	bfs1.push({ 1,1 });
	while (!bfs1.empty()) {
		pair<int, int> p = bfs1.front();
		bfs1.pop();
		for (int i : adj[p.first]) {
			if (vis1[i])
				continue;
			if (p.second + 1 > md) {
				md = p.second + 1;
				node1 = i;
			}
			bfs1.push({ i,p.second + 1 });
		}
		vis1[p.first] = true;
	}
	//printf("%d", node1);

	queue<pair<int, int>> bfs2;
	int di = 1;
	int node2 = node1;
	bfs2.push({ node1,1 });
	while (!bfs2.empty()) {
		pair<int, int> p = bfs2.front();
		bfs2.pop();
		for (int i : adj[p.first]) {
			if (vis2[i])
				continue;
			if (p.second + 1 > di) {
				di = p.second + 1;
				node2 = i;
			}
			bfs2.push({ i,p.second + 1 });
		}
		vis2[p.first] = true;
	}

	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 1; i <= N;i++) {
			if (i != node1 && i != node2 &&!inactive[i] && nOfC[i] == 1) {
				inactive[i] = true;
				for (int j : adj[i]) {
					nOfC[j]--;
				}
				flag = true;
			}
		}
	}

	int c1 = -1;
	int c2 = -1;
	int co = 1;
	int idx = node1;
	bool cust = false;
	while (idx != node2) {
		for (int i : adj[idx]) {
			if (inactive[i])
				continue;
			if (co == 1) {
				if (c1 == -1)
					c1 = c[idx];
				else if (c1 != c[idx]) {
					cust = true;
					idx = node2;
					break;
				}
				co = 2;
			}
			else {
				if (c2 == -1)
					c2 = c[idx];
				else if (c2 != c[idx]) {
					cust = true;
					idx = node2;
					break;
				}
				co = 1;
			}
			inactive[idx] = true;
			idx = i;
			break;
		}
	}

	if (co == 1) {
		if (c1 == -1)
			c1 = c[idx];
		else if (c1 != c[idx]) {
			cust = true;
		}
		co = 2;
	}
	else {
		if (c2 == -1)
			c2 = c[idx];
		else if (c2 != c[idx]) {
			cust = true;
		}
		co = 1;
	}
	if (!cust)
		di--;

	printf("%d", di);

	return 0;
}