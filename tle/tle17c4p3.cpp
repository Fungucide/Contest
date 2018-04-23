#include <stdio.h>
#include <vector>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 300001

using namespace std;

int N, M, D, curItem[MAXN], nItem[MAXN], parent[MAXN];
bool flag = false, has[MAXN];

bool update(int item) {
	if (item == 1)
		return true;
	if (has[item])
		return false;
	has[item] = true;
	if (parent[item] == 0)
		return false;
	curItem[parent[item]]++;
	if (curItem[parent[item]] == nItem[parent[item]])
		return update(parent[item]);
	return false;
}

int main() {
	scan(N);scan(M);scan(D);
	int tar, num, item;
	for (int i = 0;i < M;i++) {
		scan(tar);scan(num);
		nItem[tar] = num;
		for (int j = 0;j < num;j++) {
			scan(item);
			parent[item] = tar;
		}
	}
	for (int i = 0; i < D;i++) {
		scan(item);
		if (update(item)) {
			printf("%d\n", i + 1);
			flag = true;
			break;
		}
	}
	if (!flag)
		printf("%d\n", -1);
	return 0;
}