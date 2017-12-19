#include <stdio.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 500001

int N, psa[651][651], scores[MAXN][2];

int main() {
	scan(N);
	for (int i = 0; i < N;i++) {
		scan(scores[i][0]);scan(scores[i][1]);
		psa[scores[i][0]][scores[i][1]]++;
	}
}