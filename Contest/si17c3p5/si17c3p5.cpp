#include <stdio.h>
#include <vector>
#include <queue>
#include <unordered_map>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 100001
#define ll long long

using namespace std;

int N, par[MAXN];
ll val[MAXN];
bool set[MAXN];
vector<pair<int, ll>> adj[MAXN];
queue<int> q;
unordered_map<ll, ll> freq;

int main() {
	scan(N);
	int a, b;
	char c;
	for (int i = 1; i < N; i++) {
		scan(a); scan(b);
		c = getchar();
		a--;b--;
		adj[a].push_back({ b,c == 'r' ? 1 : -1 });
		adj[b].push_back({ a,c == 'r' ? 1 : -1 });
	}
	q.push(0);
	freq[0] = 1;
	ll res = 0;
	while (!q.empty()) {
		int idx = q.front();
		q.pop();
		for (pair<int, int> p : adj[idx]) {
			if (!set[p.first]) {
				par[p.first] = idx;
				ll *v = &val[p.first];
				*v = val[idx] + p.second;

				if (freq.find(-*v + 1) != freq.end()) {
					res += freq[-*v + 1];
					if (val[par[p.first]] == -*v + 1)
						res--;
				}
				if (freq.find(-*v - 1) != freq.end()) {
					res += freq[-*v - 1];
					if (val[par[p.first]] == -*v - 1)
						res--;
				}

				auto point = freq.find(*v);
				if (point != freq.end())
					point->second++;
				else
					freq[*v] = 1;
				q.push(p.first);
			}
		}
		set[idx] = true;
	}

	printf("%lld", res);

	return 0;
}