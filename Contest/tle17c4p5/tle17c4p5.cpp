#include <stdio.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 200001

ll N, M, _fac[MAXN], res[MAXN];

ll fac(int n) {
	if (_fac[n] == 0)
		_fac[n] = (n * fac(n - 1));
	return _fac[n];
}

ll pt(int r) {
	if (fac(r) == 0 || fac(N - r) == 0)
		return 0;
	return (fac(N) / ((fac(r)*fac(N - r))))%M;
}

int main() {
	scan(N);scan(M);
	_fac[0] = 1;
	_fac[1] = 1;
	int i;
	for (i = 0; i * 2 < N;i++) {
		res[i] = pt(i);
		printf("%lld\n", res[i]);
	}
	if (N & 1) {
		printf("%lld\n", pt(N / 2 + 1));
	}
	for (;i >= 0;i--) {
		printf("%lld\n", res[i]);
	}
	return 0;
}