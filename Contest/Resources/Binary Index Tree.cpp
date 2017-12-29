#include <stdio.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 100000 //1e5
#define BIT int

int N, bit[MAXN];
//NOTE: p is inclusive [0,p]
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
	scan(N);
}