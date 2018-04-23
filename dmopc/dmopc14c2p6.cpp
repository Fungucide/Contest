#include <stdio.h>
#include <algorithm>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 100001
#define NUM int

using namespace std;

struct queryD {
	int idx, lower, higher, mass;
	bool operator<(const queryD& rhs)const {
		return mass > rhs.mass;
	}
};

int N, Q, bit[MAXN], mass[MAXN], qRes[MAXN];
pair<int, int> trees[MAXN];
queryD q[MAXN];

void update(int p, NUM v) {
	p++;
	for (int x = p; x <= N; x += x&-x)
		bit[x] += v;
}

NUM query(int p) {
	p++;
	NUM res = 0;
	for (int x = p; x > 0; x -= x&-x)
		res += bit[x];
	return res;
}

NUM res(int a, int b) {
	return query(b) - query(a - 1);
}

void construct(NUM *val) {
	for (int i = 0; i <= N; i++) {
		bit[i] += val[i];
		bit[i + (i&-i)] += bit[i];
	}
}

int main() {
	scan(N);
	int a, b, c;
	for (int i = 0;i < N;i++) {
		scan(a);
		trees[i] = { a,i };
	}
	sort(trees, trees + N);
	scan(Q);
	for (int i = 0;i < Q;i++) {
		scan(a);scan(b);scan(c);
		q[i] = queryD{ i,a,b,c };
	}
	sort(q, q + Q);
	int tIdx = N - 1;
	for (int i = 0;i < Q;i++) {
		for (;trees[tIdx].first >= q[i].mass&& tIdx >= 0;tIdx--)
			update(trees[tIdx].second, trees[tIdx].first);
		qRes[q[i].idx] = res(q[i].lower, q[i].higher);
	}
	for (int i = 0;i < Q;i++) {
		printf("%d\n", qRes[i]);
	}
	return 0;
}