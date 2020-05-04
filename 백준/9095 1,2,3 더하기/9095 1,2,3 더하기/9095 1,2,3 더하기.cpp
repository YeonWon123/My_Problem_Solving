#include <iostream>
using namespace std;

int dp[11];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// dp 배열 채우기
	// dp[i] : i를 1,2,3의 합으로 나타내는 방법의 수
	dp[1] = 1; // 1을 1,2,3으로 만드는 경우 1개
	dp[2] = 2; // 2를 1,2,3으로 만드는 경우 2개
	dp[3] = 4; // 3을 1,2,3으로 만드는 경우 3개
	for (int i = 4; i < 11; i++) {
		// i = 1 + (i-1을 만드는 경우)
		// i = 2 + (i-2를 만드는 경우)
		// i = 3 + (i-3을 만드는 경우)
		// i를 1,2,3으로 만들 수 있는 경우의 수는 위 3가지의 합
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}


	int T, n; cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << dp[n] << "\n";
	}


	return 0;
}