#include <stdio.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 100001
#define MIN(a,b) (a<b?a:b)

int N, M, gcdSeg[MAXN * 2], gcdCount[MAXN * 2], minSeg[MAXN * 2];

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x%y);
}

void buildGCD() {
	for (int i = N - 1; i > 0; --i) {
		gcdSeg[i] = gcd(gcdSeg[i << 1], gcdSeg[i << 1 | 1]);
		gcdCount[i] = 0;
		if (gcdSeg[i] == gcdSeg[i << 1])
			gcdCount[i] += gcdCount[i << 1];
		if (gcdSeg[i] == gcdSeg[i << 1 | 1])
			gcdCount[i] += gcdCount[i << 1 | 1];
	}
}

void modifyGCD(int p, int value) {
	for (gcdSeg[p += N] = value; p > 1; p >>= 1) {
		gcdSeg[p >> 1] = gcd(gcdSeg[p], gcdSeg[p ^ 1]);
		gcdCount[p >> 1] = 0;
		if (gcdSeg[p >> 1] == gcdSeg[p])
			gcdCount[p >> 1] += gcdCount[p];
		if (gcdSeg[p >> 1] == gcdSeg[p ^ 1])
			gcdCount[p >> 1] += gcdCount[p ^ 1];
	}
}

int queryGCD(int l, int r) {  // sum on interval [l, r)
	int res = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) {
			res = gcd(res, gcdSeg[l]);
			l++;
		}
		if (r & 1) {
			r--;
			res = gcd(res, gcdSeg[r]);
		}
	}
	return res;
}

int queryCount(int l, int r) {
	int curGcd = 0;
	int preGcd = 0;
	int res = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) {
			preGcd = curGcd;
			curGcd = gcd(curGcd, gcdSeg[l]);
			if (curGcd != preGcd)
				res = 0;
			if (curGcd == gcdSeg[l])
				res += gcdCount[l];
			l++;
		}
		if (r & 1) {
			r--;
			preGcd = curGcd;
			curGcd = gcd(curGcd, gcdSeg[r]);
			if (curGcd != preGcd)
				res = 0;
			if (curGcd == gcdSeg[r])
				res += gcdCount[r];
		}
	}
	return res;
}

void buildMIN() {
	for (int i = N - 1; i > 0; --i)
		minSeg[i] = MIN(minSeg[i << 1], minSeg[i << 1 | 1]);
}

void modifyMIN(int p, int value) {
	for (minSeg[p += N] = value; p > 1; p >>= 1) {
		minSeg[p >> 1] = MIN(minSeg[p], minSeg[p ^ 1]);
	}
}

int queryMIN(int l, int r) {  // sum on interval [l, r)
	int res = 1000000002;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) {
			res = MIN(res, minSeg[l]);
			l++;
		}
		if (r & 1) {
			r--;
			res = MIN(res, minSeg[r]);
		}
	}
	return res;
}


int main() {
	scan(N); scan(M);
	int a, b;
	for (int i = 0; i < N; ++i) {
		scan(a);
		gcdSeg[N + i] = a;
		minSeg[N + i] = a;
		gcdCount[N + i] = 1;
	}
	buildGCD();
	buildMIN();
	char c;
	for (int i = 0; i < M; ++i) {
		c = getchar();
		scan(a); scan(b);
		a--;
		if (c == 'C') {
			modifyGCD(a, b);
			modifyMIN(a, b);
		}
		else if (c == 'M') {
			printf("%d\n", queryMIN(a, b));
		}
		else if (c == 'G') {
			printf("%d\n", queryGCD(a, b));
		}
		else if (c == 'Q') {
			printf("%d\n", queryCount(a, b));
		}
	}
	return 0;
}
