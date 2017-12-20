#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAXN 100001
#define MAXM 200001

using namespace std;

struct edge {
	int w, x, y, a;
	bool operator<(const edge& rhs) const { if (w != rhs.w) { return w < rhs.w; } else { return a > rhs.a; } }
};

int disjoint[MAXN], n, m, d, maxE, days, numEdge = 0;
vector<edge> edges;

void construct() {
	for (int i = 0; i < n; i++)
		disjoint[i] = i;
}

int find(int x) {
	if (disjoint[x] == x)
		return x;
	return disjoint[x] = find(disjoint[x]);
}

bool cmp(int x, int y) {
	return find(x) == find(y);
}

bool merge(int x, int y) {
	disjoint[find(y)] = find(x);
	return true;
}

int main()
{
	scanf_s("%d %d %d", &n, &m, &d);
	int a, b, c;
	for (int i = 1; i <= m; i++) {
		scanf_s("%d %d %d", &a, &b, &c);
		if (i < n) {
			edges.push_back({ c,a,b, 1 });
		}
		else {
			edges.push_back({ c,a,b, 0 });
		}
	}
	sort(edges.begin(), edges.end());
	int enable = 0;
	int disable = 0;
	edge e;
	construct();
	int i;
	for (i = 0; i < edges.size(); i++) {
		e = edges[i];
		if (!cmp(e.x, e.y)) {
			merge(e.x, e.y);
			maxE = e.w;
			numEdge++;
			if (e.a == 0)
				enable++;
		}
		else {
			if (e.a == 1)
				disable++;
		}
		if (numEdge == n - 1)break;
	}

	if (enable > disable) {
		days = enable;
	}
	else {
		days = disable;
	}

	construct();
	for (edge ed : edges) {
		if (!cmp(ed.x, ed.y)) {
			if (ed.w < maxE || (ed.w == maxE && ed.a)) {
				merge(ed.x, ed.y);
			}
			else if (ed.a && ed.w <= d) {
				printf("%d\n", days - 1);
				return 0;
			}
		}
	}

	printf("%d\n", days);
	return 0;
}

