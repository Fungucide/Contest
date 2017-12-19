#define _SRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define MAXG 376

int G;
double cust[MAXG][3];

int main() {
	scanf("%d", &G);
	for (int i = 0; i < G; i++) {
		scanf("%d%d%d", &cust[i][0], &cust[i][1], &cust[i][2]);
	}
	int max = 0;
	for (double a = 0; a <= 100; a++) {
		for (double b = a; b <= 100; b++) {
			int count = 0;
			for (int i = 0; i < G; i++) {
				double royi = a + (b - a)*cust[i][0] / (double)100;
				if (royi >= cust[i][1] && royi <= cust[i][2])
					count++;
			}
			if (count > max)
				max = count;
		}
	}
	printf("%d", max);
}