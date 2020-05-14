#include <iostream>
using namespace std;

int arr[1000000];
long long answer = 0;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		int max_value = 0;
		answer = 0;
		// 뒤에서부터 1차원 dp
		for (int j = N - 1; j >= 0; j--) {
			if (max_value < arr[j]) max_value = arr[j];
			if (max_value > arr[j]) answer += max_value - arr[j];
		}
		cout << answer << "\n";
	}
}