#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <functional>
#include <queue>
#define MAX 10

using namespace std;

pair<int, int> val[MAX][MAX];
bool vis[MAX][MAX];
int sx = -1, sy = -1, tall = 0, R, C, tree[MAX][MAX], dir[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
vector<pair<int, int>> larg;

int main() {
	cin >> R >> C;
	char ln;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> ln;
			if (ln == 'X') {
				val[j][i] = { 0,0 };
				queue.push({ j,i });
				sx = j;
				sy = i;
			}
			else if (ln != '.') {
				tree[j][i] = ln - '0';
				if (tree[j][i] == tall) {
					larg.push_back({ j,i });
				}
				else if (tree[j][i]>tall) {
					larg.clear();
					larg.push_back({ j,i });
					tall = tree[j][i];
				}
				val[j][i] = { 1 << 30,1 << 30 };
			}
			else
				val[j][i] = { 1 << 30,1 << 30 };
		}
	}

	while (!queue.empty()) {
		pair<int, int >cord = queue.top();
		queue.pop();
		int x = cord.first;
		int y = cord.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < C&&ny >= 0 && ny < R) {
				int first = val[x][y].first + tree[nx][ny];
				int second = ((tree[nx][ny] == 0) ? val[x][y].second : val[x][y].second + 1);
				if (val[nx][ny] > pair<int, int>{first, second}) {
					val[nx][ny] = { first, second };
					queue.push({ nx,ny });
				}
			}
		}
	}

	double minDis = -1;
	int mx, my;
	for (pair<int, int> p : larg) {
		double dis = sqrt(((double)sx - (double)p.first)*((double)sx - (double)p.first) + ((double)sy - (double)p.second)*((double)sy - (double)p.second));
		if (minDis == -1 || dis < minDis) {
			minDis = dis;
			mx = p.first;
			my = p.second;
		}
	}

	cout << val[mx][my].second - 1 << "\n";

	return 0;
}