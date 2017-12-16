// dmpg15s5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"

using namespace std;


int main()
{
	int n, f;
	scanf("%d %d", &n, &f);
	int map[10001][10001];
	memset(map, -1, sizeof(map[0][0]) * n * n);
	for (int i = 0; i < f; i++) {
		int x, y, w, h;
		scanf("%d %d %d %d", &x, &y, &w, &h);
		map[x][y] *= -1;
		map[x][y + h] *= -1;
		map[x + w][y] *= -1;
		map[x + w][y + h] *= -1;
	}

	for (int i = 0; i <= n; i++) {
		int smear = -1;
		for (int j = 0; j <= n; j++) {
			if (map[i][j] == 1) {
				smear *= -1;
				map[i][j] = smear;
			}
			if (smear == 1) {
				map[i][j] = 1;
			}
		}
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		int flag = -1;
		for (int j = 0; j < n; j++) {
			if (map[j][i] == 1) {
				flag *= -1;
			}
			if (flag == 1) {
				count++;
			}
		}
	}
	printf("%d", count);
	return 0;
}

