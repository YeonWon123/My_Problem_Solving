#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001] = { 0, };

int main(void)
{
	int N;
	cin >> N;

	// dp 배열 초기화
	dp[1] = 0;

	// bottom-up 풀이
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		// 2나 3으로 나누어떨어질 경우, 그 경로가 더 빠른지를 검증
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		// cout << i << " : " << dp[i] << endl;
	}
	cout << dp[N];
	return 0;
}

/*
// 잘못된 Greedy 접근법
int main(void)
{
	int X;
	cin >> X;

	int ans = 0;
	while (X != 1) {
		if (X % 3 == 0)
			X = X / 3;
		else if (X % 2 == 0)
			X = X / 2;
		else
			X = X - 1;
		ans++;
	}

	cout << ans;
}
*/