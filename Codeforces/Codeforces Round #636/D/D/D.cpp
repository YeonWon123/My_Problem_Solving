#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

struct point {
	int sum;
	int first;
	int second;
};

point arr[200000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	int n, k;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n / 2; i++) {
			cin >> arr[i].first;
		}

		for (int j = n / 2 - 1; j > -1; j--) {
			cin >> arr[j].second;
			arr[j].sum = arr[j].first + arr[j].second;
		}

		int now = 999999;
		int sw = 0;
		int ans = n / 2;
		int p;
		for (int i = 0; i < n / 2; i++) {
			p = arr[i].sum;
			now = 999999;
			sw = 0;
			for (int j = 0; j < n / 2; j++) {
				if (arr[j].sum != p) {
					if (sw == 0) {
						now = 0;
						sw = 1;
					}

					if (abs(arr[j].sum - p) >= k) {
						now = now + 2;
					}
					else {
						now = now + 1;
					}
				}
			}
			if (sw == 0) {
				ans = 0;
				break;
			}
			ans = min(ans, now);
		}
		ans = min(ans, n / 2);
		cout << ans << "\n";
	}

	return 0;
}