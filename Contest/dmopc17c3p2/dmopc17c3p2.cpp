#include <stdio.h>
#include <queue>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 100001

using namespace std;

int N;
bool oc[MAXN];

int main() {
	scan(N);
	int s;
	for (int i = 0;i < N;i++) {
		scan(s);
		oc[i] = (s == 1);
	}
	queue<int>moves;
	for (int i = 0;i < N - 1;i++) {
		if (oc[i]) {
			moves.push(i + 2);
			oc[i] = false;
			oc[i + 1] = !oc[i + 1];

			if (i + 2 < N)
				oc[i + 2] = !oc[i + 2];

		}
	}

	if (oc[N - 1]) {
		for (int i = N - 2;i >= 1;i -= 3)
			moves.push(i);
		if (N % 3 == 0)
			for (int i = 2;i < N;i += 3)
				moves.push(i);
		else
			for (int i = 1;i <= N;i += 3)
				moves.push(i);
	}

	printf("%d\n", moves.size());
	while (!moves.empty()) {
		printf("%d\n", moves.front());
		moves.pop();
	}

	return 0;
}