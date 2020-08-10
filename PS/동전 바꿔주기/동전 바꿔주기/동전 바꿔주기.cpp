#include <iostream>
using namespace std;

int p[100];
int n[100];
int dp[10001] = { 0 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, k;
	cin >> T >> k;
	for (int i = 0; i < k; i++) {
		cin >> p[i] >> n[i];
	}

	// √ ±‚»≠
	dp[0] = 1;
	for (int i = 0; i < k; i++) {
		cout << p[i] << " " << n[i] << "\n";
		for (int j = 10000; j > 0; j--) {
			for (int q = 1; q <= n[i]; q++) {
				if (j - p[i] * q >= 0)
					dp[j] += dp[j - p[i] * q];
			}
		}
	}

	cout << dp[T];
}