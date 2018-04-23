#include <math.h>
#include <iostream>

using namespace std;

bool isPrime(long long n) {
	for (long i = 3; i < ceil(sqrt(n)) + 1; i += 2) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	long long n;
	cin >> n;
	if (n == 1) {
		cout << n + 1 << endl;
	}
	else if (isPrime(n)) {
		cout << n << endl;
	}
	else {
		long long cur;
		if (n % 2 == 0) {
			cur = n + 1;
		}
		while (true) {
			cur += 2;
			for (long long i = 3; i < ceil(sqrt(n)) + 1; i += 2) {
				if (n%i == 0) {
					continue;
				}
			}
			break;
		}
		cout << cur << endl;
	}
	return 0;
}