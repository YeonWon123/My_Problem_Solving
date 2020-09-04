#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	int a, b;
	while (T--) {
		cin >> a >> b;
		if (a > b) {
			if ((a - b) % 10 == 0) {
				cout << (a - b) / 10 << "\n";
			}
			else {
				cout << (a - b) / 10 + 1 << "\n";
			}
		}
		else if (a < b) {
			if ((b - a) % 10 == 0) {
				cout << (b - a) / 10 << "\n";
			}
			else {
				cout << (b - a) / 10 + 1 << "\n";
			}
		}
		else {
			cout << 0 << "\n";
		}
	}

	return 0;
}