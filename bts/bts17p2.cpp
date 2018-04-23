#include <iostream>

using namespace std;

int g;

int main()
{
	cin >> g;
	double c = 1;
	double a, b;
	double e = 1;
	double p = 1;
	for (int i = 0; i < g; i++) {
		cin >> a >> b;
		if (e*a < 0 || p*b<0) {
			c *= e / p;
			a = 1;
			b = 1;
		}
		e *= a;
		p *= b;
	}
	c *= e / p;
	cout << c;
	return 0;
}

