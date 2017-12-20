#include <stdio.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 1000002

using namespace std;

int N, M, K, con[MAXN], disjoint[MAXN], size[MAXN];
bool notCycle[MAXN];

void construct() {
	for (int i = 0; i < N; i++) {
		disjoint[i] = i;
		size[i] = 1;
	}
}

int find(int x) {
	if (disjoint[x] == x)
		return x;
	return disjoint[x] = find(disjoint[x]);
}

bool cmp(int x, int y) {
	return find(x) == find(y);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		disjoint[y] = x;
		size[x] += size[y];
		size[y] = 0;
	}
}


int main() {
	scan(N);scan(M);scan(K);
	construct();
	int a, b;
	for (int i = 0; i < M;i++) {
		scan(a);scan(b);
		a--;b--;
		merge(a, b);
		con[a]++;
		con[b]++;
	}

	for (int i = 0; i < N;i++)
		if (con[i] != 2)
			notCycle[find(i)] = true;

	int res = 0;
	int sev = 0;
	for (int i = 0; i < N;i++) {
		if (size[i] != 0) {
			int rem = size[i] % K;
			res += size[i] - rem;
			if (size[i] != K) {
				sev += rem == 0 ? size[i] / K - 1 : size[i] / K;
				if (!notCycle[i])
					sev++;
			}
		}
	}
	if (res == 0)
		sev = 0;
	printf("%d %d\n", res, sev);
	return 0;
}