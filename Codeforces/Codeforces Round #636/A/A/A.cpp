#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	int n, x, ans, i;
	while (t--) {
		i = 2;
		cin >> n;

		x = 3;
		while (1) {
			ans = n / x;
			if ((double)n / x == ans) {
				break;
			}
			x += pow(2, i);
			i++;
		}
		cout << ans << "\n";
	}

	return 0;
}