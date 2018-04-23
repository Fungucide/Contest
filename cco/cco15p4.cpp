#include <iostream>
#include <vector>
#include <string>
#define MAX 2001

using namespace std;

int N, M, leftBlock[MAX][MAX];
char grid[MAX][MAX];
bool outside[MAX][MAX];
vector<pair<int, int>> blocking[MAX][MAX], list;

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[j][i];
			if (grid[j][i] != '.')
				list.push_back({ j,i });
		}
	}

	int x, y, xMove, yMove;

	for (pair<int, int> p : list) {
		x = p.first;
		y = p.second;
		xMove = 0;
		yMove = 0;
		if (grid[x][y] == 'N')
			yMove = -1;
		else if (grid[x][y] == 'S')
			yMove = 1;
		else if (grid[x][y] == 'E')
			xMove = 1;
		else if (grid[x][y] == 'W')
			xMove = -1;
		for (x += xMove, y += yMove; x >= 0 && x < M && y >= 0 && y < N; x += xMove, y += yMove) {
			if (grid[x][y] != '.') {
				leftBlock[p.first][p.second]++;
				blocking[x][y].push_back(p);
			}
		}
	}
	bool flag = true;
	while (flag) {
		flag = false;
		for (pair<int, int> p : list) {
			if (!outside[p.first][p.second] && leftBlock[p.first][p.second] == 0) {
				printf("(%d,%d)\n", p.second, p.first);
				for (pair<int, int> p2 : blocking[p.first][p.second]) {
					leftBlock[p2.first][p2.second]--;
				}
				flag = true;
				outside[p.first][p.second] = true;
			}
		}
	}
	return 0;
}