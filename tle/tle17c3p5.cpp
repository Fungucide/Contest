#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <algorithm>
#define MAXPOW 1953127

using namespace std;

long long mul = 1, N, arr[MAXPOW], A[9], a1[MAXPOW], a2[MAXPOW];

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
		mul *= A[i];
	}
	for (int i = 0; i < mul; i++) {
		scanf("%lld", &arr[i]);
		a1[i] = arr[i];
		a2[i] = arr[i];
	}

	int d = 1, digNum = N, dim = 1;

	for (int rep = 0; rep < N; rep++) {
		d = dim, dim *= A[--digNum];
		for (int i = 0; i < mul; i++) {
			if (i >= d && (i - d) / dim == i / dim)
				a2[i] += a1[i - d];
			if (i + d < mul && (i + d) / dim == i / dim)
				a2[i] += a1[i + d];
		}
		for (int i = 0; i < mul; i++) {
			a1[i] = a2[i];
		}
	}

	for (int i = 0; i < mul; i++) {
		printf("%lld\n", a1[i] - arr[i]);
	}

	return 0;
}