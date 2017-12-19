#include <stdio.h>
#include <math.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 20

int N, sweet[MAXN];

int main() {
	scan(N);
	for (int i = 0;i < N;i++)
		scan(sweet[i]);

	int removed = 0;
	int perm = 0;
	int min = 1 << 30;
	int a, b;
	for (int i = 0;i <= 2 << N - 1;i++) {
		for (int rem = 0;rem <= 2 << N - 1;rem++) {
			a = 0, b = 0;
			for (int j = 0;j < N;j++) {
				if ((rem >> j & 1) == 0)
					if ((i >> j & 1) == 0)
						a += sweet[j];
					else
						b += sweet[j];
			}
			if (a != 0 && b != 0) {
				int res = abs(a - b);
				if (res < min) {
					min = res;
					perm = i;
					removed = rem;
				}
			}
		}
	}
	for (int j = 0;j < N;j++) {
		if ((removed >> j & 1) == 0)
			if ((perm >> j & 1) == 0)
				printf("%d ", j + 1);
	}
	printf("\n");
	for (int j = 0;j < N;j++) {
		if ((removed >> j & 1) == 0)
			if ((perm >> j & 1) == 1)
				printf("%d ", j + 1);
	}
	printf("\n");
	return 0;
}