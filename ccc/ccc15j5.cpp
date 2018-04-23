#include <iostream>

using namespace std;
int n, k;
int dp[251][251][251];
int f(int a, int b, int c) {
	if (dp[a][b][c] == -1) {
		if (a == k - 1 && b + c <= n) {
			dp[a][b][c] = 1;
			return 1;
		}
		else if (b == n && a <= k - 1) {
			dp[a][b][c] = 0;
			return 0;
		}
		int m = 0;
		for (int i = b + c; i <= n; i++) {
			m += f(a + 1, i, i - b);
		}
		dp[a][b][c] = m;
	}
	return dp[a][b][c];
}
int main()
{
	cin >> n;
	cin >> k;
	for (int i = 0; i < 251; i++) {
		for (int j = 0; j < 251; j++) {
			for (int h = 0; h < 251; h++) {
				dp[i][j][h] = -1;
			}
		}
	}
	cout << f(0, 0, 1) << endl;
	return 0;
}
