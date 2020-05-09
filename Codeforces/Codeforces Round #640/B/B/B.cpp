#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	int n, k;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		if (n < k) {
			cout << "NO\n";
			continue;
		}
		if (n == k) {
			cout << "YES\n";
			for (int i = 0; i < n; i++) {
				cout << 1 << " ";
			}
			cout << "\n";
			continue;
		}

		if (n % 2 == 1 && k % 2 == 0) {
			cout << "NO\n"; 
			continue;
		}

		if (n / 2 >= k) {
			cout << "YES\n";
			// Â¦¼ö
			int ans = n;
			if (n % 2 == 0) {
				for (int i = 0; i < k-1; i++) {
					cout << 2 << " ";
					ans -= 2;
				}
				cout << ans << "\n";
			}
			else {
				for (int i = 0; i < k - 1; i++) {
					cout << 1 << " ";
					ans -= 1;
				}
				cout << ans << "\n";
			}
		}
		else {
			if ((n % 2 == 0 && k % 2 == 0) || (n % 2 == 1 && k % 2 == 1)) {
				cout << "YES\n";
				int ans = n;
				for (int i = 0; i < k - 1; i++) {
					cout << 1 << " ";
					ans -= 1;
				}
				cout << ans << "\n";
			}
			else {
				cout << "NO\n";
			}
		}

	}

	return 0;
}