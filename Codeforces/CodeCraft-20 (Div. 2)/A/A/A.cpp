#include <iostream>
using namespace std;

int n, m;
int sum, temp, ans;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		sum = 0;
		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			cin >> temp;
			sum += temp;
		}

		ans = m;
		while (sum - ans < 0) {
			ans--;
		}
		cout << ans << "\n";
	}

	return 0;
}