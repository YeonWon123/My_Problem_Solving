#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001] = { 0, };

int main(void)
{
	int N;
	cin >> N;

	// dp �迭 �ʱ�ȭ
	dp[1] = 0;

	// bottom-up Ǯ��
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		// 2�� 3���� ��������� ���, �� ��ΰ� �� �������� ����
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
// �߸��� Greedy ���ٹ�
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