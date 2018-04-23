#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
struct query {
	int t, x, y;
};
vector<query> cmd;
int nums[1000001];
unordered_map<int, int> comp;
int toId[1000001];
int toVal[1000001];
int bit[1000001];
int n;
int sum(int idx) {
	int res = 0;
	for (; idx > 0; idx -= idx&-idx)
		res += bit[idx];
	return res;
}
void update(int idx, int val) {
	for (; idx <= n; idx += idx&-idx)
		bit[idx] += val;
}
int main()
{
	scan(n);
	int j = 0;
	for (int i = 0; i < n; ++i) {
		char c = getchar();
		if (c == 'N') {
			int x, r;
			scan(x); scan(r);
			r = -r;
			cmd.push_back({ 0,x,r });
			nums[j++] = r;
		}
		else if (c == 'M') {
			int x, r;
			scan(x); scan(r);
			r = -r;
			cmd.push_back({ 1,x });
			cmd.push_back({ 0,x,r });
			nums[j++] = r;
		}
		else {
			int k;
			scan(k);
			cmd.push_back({ 2,k });
		}
	}
	sort(nums, nums + j);
	for (int i = 0; i < j; ++i)
		comp[nums[i]] = i + 1;
	int size = 0;
	for (int i = 0; i < cmd.size(); ++i) {
		if (cmd[i].t == 0) {
			int t = comp[cmd[i].y];
			update(t, 1);
			toId[t] = cmd[i].x;
			toVal[cmd[i].x] = t;
			++size;
		}
		else if (cmd[i].t == 1) {
			update(toVal[cmd[i].x], -1);
			--size;
		}
		else {
			int l = 1, h = j;
			while (l <= h) {
				int m = (l + h) / 2;
				if (sum(m) == cmd[i].x && (m == 1 || sum(m - 1) != cmd[i].x))
					break;
				else if (sum(m) >= cmd[i].x)
					h = m - 1;
				else
					l = m + 1;
			}
			printf("%d\n", toId[(l + h) / 2]);
		}
	}
	return 0;
}