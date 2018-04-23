#include <stdio.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int N, M, K;
bool flag = false;

int main() {
	scanf("%d%d%d", &M, &K, &N);
	for (int i = 0; i <= M;i++) {
		if ((double)(i + K) / (double)N >= (double).595) {
			printf("%d\n", i);
			flag = true;
			break;
		}
	}
	if (!flag)
		printf("have mercy snew\n");
	return 0;
}