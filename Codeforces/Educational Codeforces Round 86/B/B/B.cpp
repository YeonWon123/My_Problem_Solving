#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string str;
		cin >> str;
		int sw_0 = 0;
		int sw_1 = 0;
		int sw = 0;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '0') {
				sw_0++;
			}
			else {
				sw_1++;
			}

			if (sw_0 * sw_1 != 0) {
				sw = 2;
				break;
			}
		}

		if (sw == 2) {
			char now = str[0];
			sw = 0;
			for (int j = 0; j < str.length(); j++) {
				if (j != 0 && str[j] == now) {
					if (str[j] == '1')
						cout << '0';
					else
						cout << '1';
				}
				cout << str[j];
				now = str[j];
			}
			cout << "\n";
		}
		else {
			cout << str << "\n";
		}


	}
	return 0;
}