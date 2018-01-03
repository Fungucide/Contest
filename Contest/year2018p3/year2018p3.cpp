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
#define _CRT_SECURE_NO_WARNINGS

#endif

#define MAXN 100000//1e5
#define MAXH 1000000000
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, M, K, height[MAXN], shortest = -1, first = -1, last = -1;
unordered_map<int, int> freq;
vector<int> heights;

int main() {
	scan(N);scan(M);scan(K);
	for (int i = 0; i < N;i++) {
		scan(height[i]);

		auto point = freq.find(height[i]);
		if (point != freq.end())
			point->second++;
		else
			freq[height[i]] = 1;

		if (freq[height[i]] == 1)
			heights.push_back(height[i]);
		if (shortest == -1 || height[i] < shortest) {
			shortest = height[i];
			first = i;
			last = i;
		}
		if (height[i] == shortest) {
			first = min(first, i);
			last = max(last, i);
		}
	}
	if (K == 1) {
		if (last - first < M)
			printf("%d\n", shortest + 1);
		else
			printf("%d\n", shortest);
	}
	else if (M == 1) {
		sort(heights.begin(), heights.end());
		int dif, h;
		bool flag = false;
		for (int i = 0;i < heights.size() - 1;i++) {
			h = heights[i];
			dif = heights[i + 1] - h;
			if (freq[h] * dif <= K) {
				K -= freq[h] * dif;
				freq.find(heights[i + 1])->second += freq[h];
				freq[h] = 0;
			}
			else {
				printf("%d\n", h + K / freq[h]);
				flag = true;
				break;
			}
		}
		if (!flag) {
			printf("%d\n", heights[heights.size() - 1] + K / N);
		}
	}
	return	0;
}