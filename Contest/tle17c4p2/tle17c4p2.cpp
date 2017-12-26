#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int dig[6],time;
int small = 1 << 30;
vector<int> but;

int main() {
	dig[0] = getchar() - '0';
	dig[1] = getchar() - '0';
	getchar();
	dig[2] = getchar() - '0';
	dig[3] = getchar() - '0';
	getchar();
	dig[4] = getchar() - '0';
	dig[5] = getchar() - '0';
	time = dig[0] * 36000 + dig[1] * 3600 + dig[2] * 600 + dig[3] * 60 + dig[4] * 10 + dig[5];
	getchar();
	char c;
	while ((c = getchar()) != '\n')
		but.push_back(c - '0');
	int cur = 0;
	if (but.size() != 10) {
		for (int i : but) {
			cur += i * 36000;
			for (int j : but) {
				cur += j * 3600;
				for (int k : but) {
					cur += k * 600;
					for (int l : but) {
						cur += l * 60;
						for (int m : but) {
							cur += m * 10;
							for (int n : but) {
								cur += n;
								if (abs(cur - time) < small) {
									small = abs(cur - time);
									dig[0] = i;
									dig[1] = j;
									dig[2] = k;
									dig[3] = l;
									dig[4] = m;
									dig[5] = n;
								}
								cur -= n;
							}
							cur -= m * 10;
						}
						cur -= l * 60;
					}
					cur -= k * 600;
				}
				cur -= j * 3600;
			}
			cur -= i * 36000;
		}
	}
	for (int i = 0; i < 6;i++) {
		printf("%d", dig[i]);
		if (i == 1 || i == 3)
			printf(":");
	}
	return 0;
}