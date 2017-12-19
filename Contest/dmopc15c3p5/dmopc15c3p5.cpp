#include <stdio.h>
#include <unordered_map>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXNM 40
#define ll long long

using namespace std;

int N, M, seg1, seg2;
ll p[MAXNM];
unordered_map<ll, ll> freq;

int main() {
	scan(N); scan(M);
	for (int i = 0; i < N; i++) {
		scan(p[i]);
	}
	int a;
	for (int i = 0; i < M; i++) {
		scan(a);
		p[N + i] = -a;
	}

	seg1 = (N + M) / 2;
	seg2 = seg1;
	if ((N + M) % 2 != 0)
		seg2++;

	ll sum;
	for (int i = 1; i < (1 << seg1); i++) {
		sum = 0;
		for (int j = 0; j < seg1; j++)
			if (i >> j & 1 == 1)
				sum += p[j];
		auto point = freq.find(sum);
		if (point != freq.end()) {
			ll temp = freq[sum] + 1;
			point->second = temp;
		}
		else {
			freq[sum] = 1;
		}
	}

	ll res = 0;
	if (freq.find(0) != freq.end()) {
		res += freq[0];
	}

	for (int i = 1; i < (1 << seg2); i++) {
		sum = 0;
		for (int j = 0; j < seg2; j++)
			if (i >> j & 1 == 1)
				sum += p[seg1 + j];
		if (sum == 0)
			res++;
		if (freq.find(-sum) != freq.end())
			res += freq[-sum];
	}
	printf("%lld\n", res);
	return 0;
}