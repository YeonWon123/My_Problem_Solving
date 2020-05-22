// Chained Matrix Multiplication DP

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[200];
// dp[i][j] : i ~ j ������ ���� ������ ����� �� �ʿ��� Ƚ��
int dp[200][200];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, K;
	cin >> N >> K;

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i][i] = 0;
	}


	// ���� ���̰� 1�� ��� ���� �غ���
	for (int i = 0; i < N-1; i++) {
		if (arr[i] == arr[i+1]) {
			dp[i][i + 1] = 0;
		}
		else {
			dp[i][i + 1] = 1;
		}
	}

	// ���� ���̰� 2 �̻��� ���
	for (int k = 2; k < N; k++) {
		for (int i = 0; i < N - k; i++) {
			// dp[i][i+k]�� ���ؾ� ��
			for (int j = 0; j < k; j++) {
				// dp[i][i+k] = min(dp[i][dp[i+j] + dp[i+j+1][i+k] (+1)) (j�� 0���� k-1����, arr[i]�� arr[i+j+1]�� ���� �ٸ��� +1)
				int temp = dp[i][i + j] + dp[i + j + 1][i + k];
				if (arr[i] != arr[i + j + 1]) temp++;
				if (dp[i][i + k] == -1) dp[i][i + k] = temp;
				else dp[i][i + k] = min(dp[i][i + k], temp);
			}
		}
/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				cout << dp[i][j] << "\t";
			cout << "\n";
		}

		cout << "\n\n";
*/
	}

	cout << dp[0][N - 1];
	return 0;
}