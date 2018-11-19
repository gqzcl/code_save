#include <iostream>
#include <string.h>
using namespace std;

string str;
int main(void) {
	int n;
	cin >> n;
	while (n--) {
		str.clear();
		cin >> str;
		
		int len = str.length();
		int lenl = (str.length() + 1) / 2;
		int flag = 1;
		for (int i = 0; i < lenl; i++) {
			if (str[i] != str[len - i - 1]) {
				flag = 0;
				break;
			}
		}

		if (flag) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}

	return 0;
}
