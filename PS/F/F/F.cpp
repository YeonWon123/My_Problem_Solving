#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int arr[501];
int dp[501][501];


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		int k;
		cin >> k;
		int ans = 0;
		for (int j = 0; j < k; j++) {
			cin >> arr[j];
			dp[j][j] = arr[j];
		}

		/*
		dp[i][j] : i ~ j 까지 파일을 합치는 데 드는 최소 비용
		dp[i][i] = arr[i]
		dp[i][i+1] = arr[i] + arr[i+1]
		dp[i][i+2] = min(dp[i][i] + dp[i+1][i+2], dp[i][i+1] + dp[i+2][i+2])
		dp[i][i+3] = min(dp[i][i] + dp[i+1][i+3], dp[i][i+1] + dp[i+2][i+3], dp[i][i+2] + dp[i+3][i+3])
		...
		dp[i][j] = min(dp[i][i+p] + dp[i+p+1][i+j]) ( p = 0 ~ j-1 )
		*/

		// dp[i][i]
		for (int i = 0; i < k; i++) {
			dp[i][i] = arr[i];
		}


		// dp[i][i+1]
		for (int i = 0; i < k - 1; i++) {
			dp[i][i + 1] = dp[i][i] + dp[i + 1][i + 1];
		}

		/*
		// dp[i][i+2]
		for (int i = 0; i < k - 2; i++) {
			dp[i][i + 2] = min(dp[i][i] + dp[i + 1][i + 2] * 2, dp[i][i+1] * 2 + dp[i+2][i+2]);
		}

		
		// dp[i][i+3]
		for (int i = 0; i < k - 3; i++) {
			dp[i][i + 3] = min(dp[i][i] + dp[i + 1][i + 3] * 2, min(dp[i][i + 1] * 2+ dp[i + 2][i + 3] * 2, dp[i][i+2] * 2 + dp[i+3][i+3]));
		}
		*/

		// dp[i][i+p]
		for (int p = 2; p < k; p++) {
			for (int i = 0; i < k - p; i++) {
				for (int j = 0; j < p; j++) {
					int temp1, temp2;
					temp1 = dp[i][i + j];
					temp2 = dp[i + j + 1][i + p];
					if (i != (i + j)) temp1 *= 2;
					if ((i + j + 1) != (i + p)) temp2 *= 2;
					if (dp[i][i + p] == 0) {
						dp[i][i + p] = temp1 + temp2;
					}
					else {
						dp[i][i + p] = min(dp[i][i + p], temp1 + temp2);
					}
				}
			}
		}



		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				cout << dp[i][j] << "\t";
			}
			cout << "\n";
		}

		cout << dp[0][k - 1] << "\n";
	}

	return 0;
}