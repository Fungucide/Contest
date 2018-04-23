#include <stdio.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 100003
#define ll long long

int N, Q;
ll bit[MAXN], d[MAXN];

void update(int x, ll v) {
	x++;
	for (; x <= N; x += x&-x)
		bit[x] += v;
}

ll query(int x) {
	x++;
	ll res = 0;
	for (; x > 0; x -= x&-x)
		res += bit[x];
	return res;
}

ll cust(int lb, int rb) {
	return query(rb) - query(lb - 1);
}

int main() {
	scan(N); scan(Q);
	for (int i = 0; i < N; i++) {
		scan(d[i]);
		update(i, d[i]);
	}
	char c; int a, b;
	for (int i = 0; i<Q; i++) {
		c = getchar();
		scan(a);
		scan(b);
		a--;
		if (c == 'S') {
			update(a, b - d[a]);
			d[a] = b;
		}
		else {
			b--;
			printf("%lld\n", cust(a, b));
		}
	}
	return 0;
}