#include <stdio.h>
#include <unordered_map>
#define MAXS 100002

using namespace std;

int s, k;
unordered_map<long long, long long> sector;

int main() {
	scanf("%d%d", &s, &k);
	long long n;
	for (int i = 0; i < s;i++) {
		scanf("%lld", &n);
		sector[n] = i;
	}
	long long res = 0;
	long long curIdx = 0;
	for (int i = 0; i < k;i++) {
		scanf("%lld", &n);
		res += abs(curIdx - sector[n]);
		curIdx = sector[n];
	}
	printf("%lld", res);
}