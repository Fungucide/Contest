#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#define MAXPOW 2000001
#define MAXP 21
#define MAXQ 21

int P, Q, N, Z, sz, PSA[MAXPOW];

int con(int arr[]) {
	int idx = 0, jmp = 1;
	for (int j = 0; j < P; j++, jmp *= Q)
		idx += jmp*arr[j];
	return idx;
}

void psa() {
	int d = 1, dim = Q;
	for (int j = 0; j < P; j++, d *= Q, dim = d* Q)
		for (int i = d; i < sz; i++)
			if ((i - d) / dim == i / dim) {
				PSA[i] += PSA[i - d];
			}
}

int main() {
	scanf("%d%d%d", &P, &Q, &N);
	sz = pow(Q, P);
	for (int i = 0; i < N; i++) {
		int arr[MAXP];
		for (int j = 0; j < P; j++)
			scanf("%d", &arr[j]);
		PSA[sz - con(arr) - 1]++;
	}

	psa();

	scanf("%d", &Z);

	for (int i = 0; i < Z; i++) {
		int arr[MAXP];
		for (int j = 0; j < P; j++)
			scanf("%d", &arr[j]);
		printf("%d\n", PSA[sz - con(arr) - 1]);
	}


	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#define MAXPOW 2000001
#define MAXP 21
#define MAXQ 21

int P, Q, N, Z, sz, PSA[MAXPOW];

int con(int arr[]) {
	int idx = 0, jmp = 1;
	for (int j = 0; j < P; j++, jmp *= Q)
		idx += jmp*arr[j];
	return idx;
}

void psa() {
	int d = 1, dim = Q;
	for (int j = 0; j < P; j++, d *= Q, dim = d* Q)
		for (int i = d; i < sz; i++)
			if ((i - d) / dim == i / dim) {
				PSA[i] += PSA[i - d];
			}
}

int main() {
	scanf("%d%d%d", &P, &Q, &N);
	sz = pow(Q, P);
	for (int i = 0; i < N; i++) {
		int arr[MAXP];
		for (int j = 0; j < P; j++)
			scanf("%d", &arr[j]);
		PSA[sz-con(arr)-1]++;
	}

	psa();

	scanf("%d", &Z);

	for (int i = 0; i < Z; i++) {
		int arr[MAXP];
		for (int j = 0; j < P; j++)
			scanf("%d", &arr[j]);
		printf("%d\n", PSA[sz-con(arr)-1]);
	}


	return 0;
}
