#include <iostream>
#include <algorithm>
using namespace std;

int a[50];
int b[50];

int main(void)
{
	long long ans = 0;
	int t, n, a_min, b_min;
	cin >> t;
	while (t--) {
		ans = 0;
		a_min = 1000000001;
		b_min = 1000000001;
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a_min = min(a_min, a[i]);
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			b_min = min(b_min, b[i]);
		}

		int counts1, counts2;
		for (int i = 0; i < n; i++) { 
			counts1 = a[i] - a_min;
			counts2 = b[i] - b_min;
			ans += max(counts1, counts2);
		}
		cout << ans << "\n";
	}
}