#include <stdio.h>
#include <algorithm>
#include <unordered_map>
#include <functional>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 200002
#define BIT long long

using namespace std;

int N, X;
double start[MAXN];
unordered_map<double, int> start;
pair<double, double> deg[MAXN];
BIT bit[MAXN];

void update(int p, BIT v) {
	p++;
	for (int x = p; x < MAXN; x += x&-x)
		bit[x] += v;
}

BIT query(int p) {
	p++;
	BIT res = 0;
	for (int x = p; x > 0; x -= x&-x)
		res += bit[x];
	return res;
}

int main() {
	scan(N);scan(X);
	int a, b;
	for (int i = 0; i < N;i++) {
		scan(a);scan(b);
		deg[i] = { (double)b / (double)a,(double)(b) / (double)(X - a) };
		start[i] = deg[i].second;
	}

	sort(deg, deg + N, greater<pair<double, double>>());
	sort(start, start + N);

	for (int i = 0; i < N;i++) {
		if (start.find(start[i]) == start.end())
			start[start[i]] = start.size();
	}

	long long res = 0;
	for (int i = 0;i < N;i++) {
		long long q = (i - query(start[deg[i].second] - 1));
		res += q*q;
		update(start[deg[i].second], 1);
	}
	printf("%lld\n", res);

	return 0;
}