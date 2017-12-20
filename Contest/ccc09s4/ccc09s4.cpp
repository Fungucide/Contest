#include <iostream>
#include <vector>
#define MAX 5000

using namespace std;

vector <pair<int, int>> adj[MAX];
vector <pair<int, int>> p;
int c[MAX];
bool v[MAX];
int n;
int t;
int k;


int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	cin >> t;
	memset(c, 2 << 5, MAX);
	for (int i = 0; i < t; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a - 1].push_back({ b - 1,c });
		adj[b - 1].push_back({ a - 1,c });
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		p.push_back({ a - 1,b });
	}
	int d;
	cin >> d;
	c[d - 1] = 0;
	while (true) {
		int min = 2 << 25;
		int idx = -1;
		for (int i = 0; i < n; i++) {
			cout << "Min value: " << i << " " << v[i] << " " << c[i] << endl;
			if (!v[i] && c[i] < min) {
				min = c[i];
				idx = i;
			}
		}
		cout << "Min set: " << idx << " " << min << endl;
		if (idx == -1) {
			break;
		}
		v[idx] = true;
		for (pair<int, int> p : adj[idx]) {
			if (!v[p.first]) {
				cout << " -Edit Value:" << c[p.first] << "->";
				if (c[p.first] > c[idx] + p.second) {
					c[p.first] = c[idx] + p.second;
				}
				cout << p.first << " " << c[p.first] << endl;
			}
		}

	}
	int min = 2 << 16;
	for (pair<int, int>pa : p) {
		if (min > c[pa.first] + pa.second) {
			min = c[pa.first] + pa.second;
		}
	}
	cout << min << "\n";
	return 0;
}

