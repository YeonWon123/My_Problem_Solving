#include <iostream>
#include <algorithm>
using namespace std;

int a[30];
int b[30];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	int n, k;
	for (int i = 0; i < t; i++) {
		int sum = 0;
		cin >> n >> k;
		for (int j = 0; j < n; j++) {
			cin >> a[j];
			sum += a[j];
		}
		for (int j = 0; j < n; j++) {
			cin >> b[j];
		}

		if (k == 0) {
			cout << sum << "\n";
		}
		else {
			sort(a, a + n);
			sort(b, b + n, greater<int>());
			for (int j = 0; j < k; j++) {
				if (a[j] > b[j]) break;
				sum -= a[j];
				sum += b[j];
			}
			cout << sum << "\n";
		}
	}

	return 0;
}