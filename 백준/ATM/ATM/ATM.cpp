#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// dp[순서][사람]
int dp[1000][1000] = { 0, };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0) {
				cin >> dp[0][j];
			}
			else {
				for (int k = 0; k < n; k++) {
					dp[i][j] = min(dp[i][j], dp[i - 1][k]);
					dp[i][j] += dp[0][j];
				}
			}
		}
	}

	return 0;
}