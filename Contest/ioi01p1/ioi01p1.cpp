#include <iostream>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXS 1026

int S, bit[MAXS][MAXS];

void update(int ux, int uy, int v) {
	ux++;
	uy++;
	for (int x = ux; x <= S; x += x&-x)
		for (int y = uy; y <= S; y += y&-y)
			bit[x][y] += v;
}

int query(int qx, int qy) {
	qx++;
	qy++;
	int res = 0;
	for (int x = qx; x > 0; x -= x&-x)
		for (int y = qy; y > 0; y -= y&-y)
			res += bit[x][y];
	return res;
}

int cust(int a, int b, int c, int d) {
	return query(c, d) + query(a - 1, b - 1) - query(a - 1, d) - query(c, b - 1);
}

int main() {
	int com, a, b, c, d;
	scan(a); scan(S);
	scan(com);
	while (com != 3) {
		if (com == 1) {
			scan(a);
			scan(b);
			scanf("%d", &c);
			update(a, b, c);
		}
		else if (com == 2) {
			scan(a);
			scan(b);
			scan(c);
			scan(d);
			printf("%d\n", cust(a, b, c, d));
		}
		scan(com);
	}
	return 0;
}