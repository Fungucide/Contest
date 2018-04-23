#include <iostream>
#include <vector>

#define MAX 10000

using namespace std;

struct link {
	int a;
	int b;
	int w;
};

int nw[MAX];
int nv[MAX];
int ncv[MAX];
vector<link> adj;
bool v[MAX];
int n;
int minVal;
int maxW;

void f(int cn) {
	v[cn] = true;
	nw[cn] = 0;
	nv[cn] = ncv[cn];
	for (link l : adj) {
		if (l.a == cn) {
			if (v[l.b]) {
				nw[cn] += l.w;
			}
			else {
				f(l.b);
				nw[cn] += nw[l.b];
				nv[cn] += nv[l.b];
			}
		}
		else if (l.b == cn) {
			if (v[l.a]) {
				nw[cn] += l.w;
			}
			else {
				f(l.a);
				nw[cn] += nw[l.a];
				nv[cn] += nv[l.a];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> minVal >> maxW;
	for (int i = 0; i < n; i++) {
		cin >> ncv[i];
	}
	int a, b, c;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		link t;
		t.a = a - 1;
		t.b = b - 1;
		t.w = c;
		adj.push_back(t);
	}
	f(0);
	int count = 0;
	for (int i = 1; i < n; i++) {
		if (nw[i] <= maxW && nv[i] >= minVal) {
			count++;
		}
	}
	cout << count << "\n";
	return 0;
}

