#include <iostream>
#include <cstring>
using namespace std;

// 투 포인터 문제 (부분합 문제로 잘못 생각하고 접근하여 시간초과 발생)
int arr[8001];

int main(void)
{
	int t;
	cin >> t;
	int n;
	for (int i = 0; i < t; i++) {
		memset(arr, 0, sizeof(arr));
		cin >> n;
		int ans = 0;

		for (int pp = 0; pp < n; pp++) {
			cin >> arr[pp];
		}

		if (n == 1) {
			cout << 0 << "\n";
			continue;
		}

		for (int pp = 0; pp < n; pp++) {
			int m = arr[pp];
			int left = 0, right = 1, result = 0, sum = 0;
			sum = arr[left] + arr[right];

			while (right < n) {
				if (sum == m) {
					ans++;
					break;
				}

				if (sum > m) {
					sum -= arr[left];
					left++;
				}

				if (sum < m || left == right) {
					right++;
					if (right == n) break;
					sum += arr[right];
				}
			}
		}
		cout << ans << "\n";
	}

	return 0;
}