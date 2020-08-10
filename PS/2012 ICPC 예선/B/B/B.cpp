#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int input[4][1000];	 // 입력값
int sum[1000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, k, n;
	cin >> T;

	while (T--) {
		int mins = 999999999, values = 0, indexs = 0;
		cin >> k >> n;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < n; j++) {
				cin >> input[i][j];
			}
			sort(input[i], input[i] + n);
		}

		for (int i = 0; i < n; i++) {
			sum[i] = input[0][i] + input[1][i] + input[2][i] + input[3][i];
			if (abs(sum[i] - k) < mins) {
				mins = abs(sum[i] - k);
				values = sum[i];
				indexs = i;
			}
		}
		// k에 최대한 유사한 값을 구하자.
		// 한 줄에서 나올 수 있는 결과를 모두 수집 후 비교

		// values가 k보다 작은 경우 : + -> -의 순서로 시도
		int temp = values - k;
		int arr[4] = { 0, };

		// +는 바로 뒤에꺼만 하면 됨
		if (indexs != n - 1) {
			for (int i = 0; i < 4; i++) {
				arr[i] = input[i][indexs + 1] - input[i][indexs];
			}
		}
		
		// -는 바로 앞에꺼만 하면 됨
		if (indexs != 0) {
			for (int i = 0; i < 4; i++) {
				if (abs(arr[i]) > )
				arr[i] = input[i][indexs] - input[i][indexs - 1];
			}
		}

		cout << values << "\n";
	}
	return 0;
}