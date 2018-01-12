#include <iostream>
#include <string>
#define MAXNM 100

using namespace std;

int n, m;
int dp[MAXNM][MAXNM][3];
int cust[MAXNM][MAXNM];
bool v[MAXNM][MAXNM];
int dir[3][2] = { { 1,0 },{ 0,-1 },{ 0,1 } };


int f(int x, int y, int d) {
	//cout << x << " " << y << "\n";
	if (x == m - 1 && y == 0) {
		return cust[x][0];
	}
	else if (d == -1 || dp[x][y][d] == -1) {
		int max = 0;
		for (int i = 0; i < 3; i++) {
			//cout << ((d == 2 && i != 1) || (d == 1 && i != 2)||(d==0)) << " " << (dir[i][0] + x < m) << " " << (dir[i][1] + y < n) << " " << (dir[i][1] + y != -1) << " " << (map[dir[i][0] + x][dir[i][1] + y] != -1) << endl;
			if (dir[i][0] + x < m && dir[i][1] + y < n && dir[i][1] + y != -1 && !v[dir[i][0] + x][dir[i][1] + y]) {
				int cur = cust[x][y] + f(dir[i][0] + x, dir[i][1] + y, i);
				if (cur > max) {
					max = cur;
				}
			}
		}
		dp[x][y][d] = max;
	}
	//cout << "<-"<<endl;
	return dp[x][y][d];
}

int main()
{
	do {
		scanf_s("%d %d\n", &n, &m);
		memset(dp, -1, sizeof(dp));
		char c;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf_s("%c", &c);
				if (c == '.') {
					cust[j][i] = 0;
				}
				else if (c != '*') {
					cust[j][i] = c - '0';
				}
				else {
					cust[j][i] = -1;
					v[j][i] = true;
				}
			}
		}
		cout << f(0, n - 1, 2) << "\n";
	} while (n != 0);
	return 0;
}

