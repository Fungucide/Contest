#include <iostream>
#include <algorithm>
#define MAXN 100000

using namespace std;

int e[MAXN];
int n;

int main()
{
	cin >> n;
	int r;
	for (int i = 0; i < n; i++) {
		cin >> r;
		e[i] = r;
	}
	sort(&e[0], &e[n]);
	int left = 1;
	int count = 0;
	int rank = 1;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (e[i] == rank && left > 0) {
			left--;
			count++;
		}
		else if (e[i] == rank && left == 0) {
			flag = true;
			break;
		}
		else if (e[i] > rank) {
			left = count * 2;
			count = 0;
			rank = e[i];
		}
	}
	if (flag) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}

	return 0;
}

