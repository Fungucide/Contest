#include <stdio.h>
#include <unordered_map>
#include <vector>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 100000

using namespace std;

int N, Q;
unordered_map<int, int> adj[MAXN];
vector<int> con[MAXN];

int main() {
	scan(N);
	int m, a, b, first;
	for (int i = 0; i < N;i++) {
		scan(m);
		scan(a);
		a--;
		first = a;
		con[i].push_back(a);
		for (int j = 1;j < m;j++) {
			scan(b);
			b--;
			con[i].push_back(b);
			adj[i][b] = a;
			a = b;
		}
		adj[i][first] = a;
	}
	scan(Q);
	int start, cur, dis, temp, max;
	for (int i = 0;i < Q;i++) {
		scan(start);
		start--;
		max = 0;
		for (int pre : con[start]) {
			cur = start;
			dis = 0;
			while (cur != start || dis == 0) {
				temp = cur;
				cur = adj[cur][pre];
				pre = temp;
				dis++;
			}
			if (dis > max)
				max = dis;
		}
		printf("%d\n", max);
	}
	return 0;
}