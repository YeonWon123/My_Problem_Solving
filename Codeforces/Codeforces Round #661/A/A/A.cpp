#include <iostream>
#include <algorithm>
using namespace std;

int a[100];

int main(void)
{
	int t, n, sw;
	cin >> t;
	while (t--) {
		cin >> n;
		sw = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);

		for (int i = 0; i < n; i++) {
			if (i != 0 && a[i] - a[i - 1] > 1) {
				sw = 1;
			}
		}
		
		if (sw == 1) cout << "NO\n";
		else cout << "YES\n";
	}
}