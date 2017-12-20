#include <iostream>

using namespace std;

int n;
int c[4];

int f(int u, int v) {
	if (u == 15) {
		if (v <= 24) {
			return v;
		}
		else {
			return -1;
		}
	}
	int max = -1;
	for (int i = 0; i < 4; i++) {
		//cout << i << " " << u << " " << (1 << i&u) << "\n";
		if (v == 0 && u == 0) {
			return f(1 << i, c[i]);
		}
		else if ((1 << i&u) == 0) {
			int res;
			res = f(1 << i | u, v + c[i]);
			if (res > max) {
				max = res;
			}
			res = f(1 << i | u, v - c[i]);
			if (res > max) {
				max = res;
			}
			res = f(1 << i | u, v * c[i]);
			if (res > max) {
				max = res;
			}
			if (v % c[i] == 0) {
				res = f(1 << i | u, v / c[i]);
				if (res > max) {
					max = res;
				}
			}
		}
	}
	return max;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int i = 0; i < 4; i++) {
			cin >> c[i];
		}
		cout << f(0, 0) << "\n";
	}
	return 0;
}

