#include <iostream>
#include <string>
#define MAXN 100001

using namespace std;

int dry[MAXN];
int dp[MAXN];
int n, m, j;

int f(int idx, int t) {
	if (idx == n) {
		return t;
	}
	else if (dp[idx] == 0) {
		int min = -1;
		for (int i = 1; i <= j; i++) {
			if (dry[idx + i] == 0) {
				continue;
			}
			else if (dry[idx + i] > t) {
				t = dry[idx + i];
			}
			int res = f(idx + i, t);
			if (min == -1 || (res != -1 && res < min)) {
				min = res;
			}
			dp[idx] = min;
		}
	}
	return dp[idx];
}

int main()
{
	cin >> n >> m >> j;
	dry[0] = 0;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		dry[a] = b;
	}
	cout << f(0, 0) << "\n";
	return 0;
}

