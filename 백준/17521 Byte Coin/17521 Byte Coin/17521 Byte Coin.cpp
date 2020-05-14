#include <iostream>
using namespace std;

int arr[20];
int dp[20] = { 0 }; // 사야 하는 지점 : 1, 팔아야 하는 지점 : 2
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	long long W;
	long long b_c = 0;
	cin >> n >> W;

	// -1 : 이전까지 감소
	// 0 : 처음
	// 1 : 이전까지 증가
	int sw = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i != 0) {
			// 증가하는 지점 -> 최대한 많이 파는 지점을 알 수 있음
			if ((sw == 0 || sw == -1) && (arr[i] > arr[i - 1])) {
				// arr[i-1]의 가격으로 최대한 많이 사야 함.
				b_c += W / arr[i-1];
				W -= W / arr[i-1] * arr[i-1];

			//	dp[i-1] = 1;
				sw = 1;
			}
			// 감소하는 지점 -> 최대한 많이 사는 지점을 알 수 있음
			else if ((sw == 0 || sw == 1) && (arr[i] < arr[i - 1])) {
				// arr[i-1]의 가격으로 최대한 많이 사야 함.
				W += (long long)b_c * arr[i - 1];
				b_c = 0;

			//	dp[i-1] = 2;
				sw = -1;
			}
		}

		// 만약 내가 마지막 지점이고 증가 중이라면
		// 마지막 날에 싹 다 판다.
		if (i == n-1 && sw == 1) {
			W += (long long)b_c * arr[i];
			b_c = 0;
		//	dp[i - 1] = 1;
		}
		// cout << i + 1 << "일 차 W : " << W << endl;
	}

	cout << W;

	return 0;
}