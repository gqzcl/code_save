#include <iostream>
using namespace std;

int main() {
	int a, b;
	while (cin >> a >> b) {
		if (a == b&&b==0) {
			return 0;
		}
		long long m = 1, n = 1;
		for (int i = a; i > a - b; i--) {
			m *= i;
		}
		for (int i = b; i > 0; i--) {
			n *= i;
		}
		cout << m/n << endl;
	}

	return 0;
}

