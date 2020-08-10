#include <iostream>
using namespace std;

int main(void)
{
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		if (n == 1 || n == 2 || n == 3) {
			cout << 1 << "\n";
		}
		else {
			cout << n / 2 << "\n";
		}
	}

	return 0;
}