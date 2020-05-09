#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	int a, b, c;
	for (int i = 0; i < t; i++) {
		cin >> a >> b >> c;
		if (c != 0 || b != 0) {
			for (int i = 0; i <= c; i++) {
				cout << "1";
			}
		}
		else {
			cout << "0";
		}
		
		for (int i = 0; i < b-1; i++) {
			if (i % 2 == 0)
				cout << "0";
			else 
				cout << "1";
		}
		if (b % 2 != 0) cout << "0";

		for (int i = 0; i < a; i++) {
			cout << "0";
		}

		if (b != 0 && b % 2 == 0)
			cout << "1";

		cout << "\n";
	}

	return 0;
}