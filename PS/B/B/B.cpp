#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int card[1000];
// dp[i][j] : i ~ j 사이에 카드가 있을 떄 Alice가 먹을 수 있는 최고 점수
// dp[i][i] = card[i];
// dp[i][j] = max(dp[i+1][j] + card[i], dp[i][j-1] + card[j])
int dp[1000][1000];
int sum[1000];
int recursion(int i, int j) {
	if (dp[i][j] != 0) return dp[i][j];

	if (i == j) return card[i];
	else {
		int res = 0;
		if (i == 0) res = sum[j];
		else res = sum[j] - sum[i - 1];
		int res2 = max(res - recursion(i + 1, j), res - recursion(i, j - 1));
		dp[i][j] = res2;
		return res2;
	}

}

int main(void)
{
	int t;
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> card[i];
			if (i == 0) {
				sum[0] = card[0];
			}
			else {
				sum[i] += sum[i - 1] + card[i];
			}
		}

		sum[0] = card[0];
		int ans = recursion(0, n - 1);
		cout << ans << "\n";
	}
}