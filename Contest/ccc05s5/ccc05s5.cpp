#include <stdio.h>
#include <unordered_map>
#include <algorithm>
#define MAXS 100002

using namespace std;

int bit[MAXS];
int scores[MAXS];
int o[MAXS];
unordered_map<int, int> map;
int t;

void update(int p, int v) {
	for (int x = p; x <= MAXS; x += x&-x)
		//example of multidimensional
		//for (int y = p; y <= n; y += y&-y)
		bit[x] += v;
}

int query(int p) {
	int res = 0;
	for (int x = p; x > 0; x -= x&-x)
		res += bit[x];
	return res;
}

int main()
{
	scanf_s("%d", &t);
	long long v = 0;
	for (int i = 0; i < t; i++) {
		scanf_s("%d", &scores[i]);
		o[i] = scores[i];
	}
	sort(scores, scores + t);
	int idx = 1;
	for (int i = 0; i < t; i++) {
		if (map.find(scores[i]) == map.end()) {
			map.insert({ scores[i], idx });
			++idx;
		}
	}
	for (int i = 0; i < t; i++) {
		v += i - query(map.at(o[i])) + 1;
		update(map.at(o[i]), 1);
	}
	printf("%.2f", v / (double)t);
	return 0;
}

