#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 8195

int N, Q, height[MAXN], bit[MAXN][MAXN];//Idx, Height 

void update(int ux, int uy, int v) {
	ux++;
	uy++;
	for (int x = ux; x <= N; x += x&-x)
		for (int y = uy; y <= N; y += y&-y)
			bit[x][y] += v;
}

int query(int qx, int qy) {
	qx++;
	qy++;
	int res = 0;
	for (int x = qx; x > 0; x -= x&-x)
		for (int y = qy;y > 0;y -= y&-y)
			res += bit[x][y];
	return res;
}

int cust(int a, int b, int c, int d) {
	return query(c, d) + query(a - 1, b - 1) - query(a - 1, d) - query(c, b - 1);
}

int main() {
	scan(N);
	int h;
	for (int i = 0;i < N;i++) {
		scan(h);
		height[i] = h;
		update(i, h, 1);
	}
	scan(Q);
	int com, a, b, c, d;
	for (int i = 0;i < Q;i++) {
		scan(com); if (com == 2) {
			scan(a);
			scan(b);
			update(a, height[a], -1);
			update(a, b, 1);
			height[a] = b;
		}
		else if (com == 1) {
			scan(a);
			scan(b);
			scan(c);
			scan(d);
			printf("%d\n", cust(a, c, b, d));
		}
	}
5	return 0;
}