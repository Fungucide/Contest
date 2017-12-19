#include <queue>
#include <stdio.h>
#define MAXN 100002
#define scanf scanf_s

using namespace std;

priority_queue<long long> pq[MAXN];
int N, cust[MAXN][3];
long long M, big = 0, sum[MAXN];//Parent Cost Leadership

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d%d", &cust[i][0], &cust[i][1], &cust[i][2]);
	}
	for (int i = N; i > 0; i--) {
		pq[i].push(cust[i][1]);
		sum[i] += cust[i][1];
		while (sum[i] > M) {
			sum[i] -= pq[i].top();
			pq[i].pop();
		}
		long long res = (long long)pq[i].size()*(long long)cust[i][2];
		if (res > big)
			big = res;
		if (pq[cust[i][0]].size() < pq[i].size()) {
			swap(pq[cust[i][0]], pq[i]);
			swap(sum[cust[i][0]], sum[i]);
		}
		while (!pq[i].empty()) {
			pq[cust[i][0]].push(pq[i].top());
			sum[cust[i][0]] += pq[i].top();
			pq[i].pop();
		}
	}
	printf("%lld", big);
	return 0;
}