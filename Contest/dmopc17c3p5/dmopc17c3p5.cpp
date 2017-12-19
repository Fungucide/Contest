#include <stdio.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MOD 1000000007ll

bool block[2000][2000];
ll M, N;
ll multMod(ll  a, ll  b) {
	if (a == 0 || b == 0) {
		return 0;
	}
	if (a == 1) {
		return b;
	}
	if (b == 1) {
		return a;
	}

	ll a2 = multMod(a, b / 2);
	if ((b & 1) == 0) {
		return (a2 + a2) % MOD;
	}
	else {
		return ((a % MOD) + (a2 + a2)) % MOD;
	}
}

ll powfast(ll a, ll b) {
	ll res = 1;
	ll curr = a;
	while (b > 0) {
		if ((b & 1) == 1) {
			res *= curr;
			res %= MOD;
		}
		curr *= curr;
		curr %= MOD;
		b >>= 1;
	}
	return res;

}

int main() {
	scan(M);scan(N);
	char c;
	for (int i = 0; i < M;i++) {
		for (int j = 0;j < N;j++) {
			c = getchar();
			if (c == 'X')
				block[j][i] = true;
		}
		getchar();
	}

	ll res = 0;
	for (int y = 0;y < M;y++) {
		for (int x = 0;x < N;x++) {

			int maxX = N-1;
			for (int ySize = 0; ySize + y < M;ySize++) {
				for (int xSize = 0;xSize + x <= maxX;xSize++) {
					if (block[xSize + x][ySize + y]) {
						maxX = xSize + x;
						break;
					}
					res = (res + multMod(xSize+1, multMod(ySize+1, (powfast(xSize+1, xSize+1) + powfast(ySize+1, ySize+1)) % MOD)))%MOD;
				}
			}

		}
	}

	printf("%lld\n", res);
	return 0;
}