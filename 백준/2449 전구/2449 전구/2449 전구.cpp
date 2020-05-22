// Chained Matrix Multiplication DP

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[200];
// dp[i][j] : i ~ j 구간을 같은 색으로 만드는 데 필요한 횟수
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


	// 구간 길이가 1인 경우 먼저 해보자
	for (int i = 0; i < N-1; i++) {
		if (arr[i] == arr[i+1]) {
			dp[i][i + 1] = 0;
		}
		else {
			dp[i][i + 1] = 1;
		}
	}

	// 구간 길이가 2 이상인 경우
	for (int k = 2; k < N; k++) {
		for (int i = 0; i < N - k; i++) {
			// dp[i][i+k]를 구해야 함
			for (int j = 0; j < k; j++) {
				// dp[i][i+k] = min(dp[i][dp[i+j] + dp[i+j+1][i+k] (+1)) (j는 0부터 k-1까지, arr[i]와 arr[i+j+1]의 값이 다르면 +1)
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