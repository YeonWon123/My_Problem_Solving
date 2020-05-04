#include <iostream>
using namespace std;

int dp[11];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// dp �迭 ä���
	// dp[i] : i�� 1,2,3�� ������ ��Ÿ���� ����� ��
	dp[1] = 1; // 1�� 1,2,3���� ����� ��� 1��
	dp[2] = 2; // 2�� 1,2,3���� ����� ��� 2��
	dp[3] = 4; // 3�� 1,2,3���� ����� ��� 3��
	for (int i = 4; i < 11; i++) {
		// i = 1 + (i-1�� ����� ���)
		// i = 2 + (i-2�� ����� ���)
		// i = 3 + (i-3�� ����� ���)
		// i�� 1,2,3���� ���� �� �ִ� ����� ���� �� 3������ ��
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}


	int T, n; cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << dp[n] << "\n";
	}


	return 0;
}