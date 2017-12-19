#include <stdio.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int N;

int main() {
	scan(N);
	int min = 1 << 30;
	int in;
	for (int i = 0;i < N;i++) {
		scanf("%d", &in);
		if (in < min)
			min = in;
	}
	printf("%d", min);
	return 0;
}