#include <iostream>
using namespace std;

int arr[100];

int main(void)
{
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	// 경우의 수 : 100C3 = 약 10만
	// 따라서 3중 for문으로 완전 탐색을 하면 구할 수 있다.
	int max_value = -1;
	int sum;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
			//	cout << arr[i] << " " << arr[j] << " " << arr[k] << "\n";
				sum = arr[i] + arr[j] + arr[k];
				if ((sum > max_value) && (sum <= M)) {
					max_value = sum;
				}
			}
		}
	}
	cout << max_value;
	return 0;
}