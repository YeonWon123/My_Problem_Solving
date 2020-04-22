#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	long long n, temp, p_max, n_max, ans, sw;
	while (t--) {
		ans = 0;
		sw = 0;
		p_max = -9999999999;
		n_max = -9999999999;

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> temp;

			if (i == 0) {
				sw = (temp > 0) ? 1 : -1;
			}

			if (temp < 0) {
				if (sw == 1) {
					sw = -1;
					ans += p_max;
					p_max = -999999;
					n_max = temp;
					if (i == n - 1) {
						sw = 2;
						ans += temp;
					}
				}
				else
					n_max = max(temp, n_max);
			}
			else {
				if (sw == -1) {
					sw = 1;
					ans += n_max;
					n_max = -999999;
					p_max = temp;
					if (i == n - 1) {
						sw = 2;
						ans += temp;
					}
				}
				else
					p_max = max(temp, p_max);
			}
		}

		if (sw != 2) {
			if (sw == 1) {
				ans += p_max;
			}
			else {
				ans += n_max;
			}
		}

		cout << ans << "\n";
	}
	return 0;
}
