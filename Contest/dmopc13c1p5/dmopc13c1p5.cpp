#define _SRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define MAXG 376

int G;
double start[MAXG][3];

int main() {
	scanf("%d", &G);
	for (int i = 0; i < G; i++) {
		scanf("%d%d%d", &start[i][0], &start[i][1], &start[i][2]);
	}
	int max = 0;
	for (double a = 0; a <= 100; a++) {
		for (double b = a; b <= 100; b++) {
			int count = 0;
			for (int i = 0; i < G; i++) {
				double royi = a + (b - a)*start[i][0] / (double)100;
				if (royi >= start[i][1] && royi <= start[i][2])
					count++;
			}
			if (count > max)
				max = count;
		}
	}
	printf("%d", max);
}