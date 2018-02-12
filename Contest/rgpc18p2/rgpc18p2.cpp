#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#define scanf scanf_s

#endif

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define MAXN 100000//1e5
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N;
double S;

int main() {
	scanf("%d %lf", &N, &S);
	double mCombo = 0;
	double cCombo = 0;
	double score = 0;
	double time;
	for (int i = 0; i < N; i++) {
		scanf("%lf", &time);
		if (time < 0.0)
			time *= -1;
		if (time <= 50) {
			score += 1.5;
			cCombo++;
		}
		else if (time <= 100) {
			score += 1.0;
			cCombo++;
		}
		else if (time <= 150) {
			score += 1.0;
			cCombo++;
		}
		else if (time <= 200) {
			score += 0.5;
			cCombo++;
		}
		else {
			score--;
			if (cCombo > mCombo)
				mCombo = cCombo;
			cCombo = 0;
		}
	}
	if (cCombo > mCombo)
		mCombo = cCombo;
	score += 0.5*mCombo;
	printf("%.1lf\n", score - S);
	return 0;
}