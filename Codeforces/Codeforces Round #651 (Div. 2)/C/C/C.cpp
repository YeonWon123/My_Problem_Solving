#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int isNumber(int n) {
	if (n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	if (n == 3) return true;
	for (int i = 3; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
		i++;
	}
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		if (n == 1) cout << "FastestFinger\n";
		else if (n == 2) cout << "Ashishgup\n";
		else if (n % 2 == 1) cout << "Ashishgup\n";
		else {
			// 2와 홀수 1개로 이루어져 있는 경우 B 승리
			// 나머지 경우 A 승리
			if (isNumber(n / 2)) {
				cout << "FastestFinger\n";
			}
			else {
				cout << "Ashishgup\n";
			}
		}
	}

	return 0;
}