#include <iostream>
using namespace std;

int arr[20];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, S;
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int ans = 0;

	// index를 이용해서 32가지 경우를 모두 해보는 방법이다.
	// 배열에 요소들을 넣고
	// index를 이진법으로 이용, 해당되는 index의 값들을 뽑아서 게산해보고
	// index의 조합에 따라 최종 결과가 달라지게 된다.

	// i가 1부터 시작하는 이유 : "크기가 양수인 부분수열"이기 때문에,
	// i = 0이면 아무것도 선택을 안하는 거니깐 말이 안된다!
	// 1 << N에서 만약 N이 5라고 하면,
	// 1 << N => 100000 (32)이다.
	// N = 5이고 { -7, -3, -2, 5, 8 } 에서 경우의 수는 32개이다.
	for (int i = 1; i < (1 << N); i++) {
		int sum = 0;
		// j는 0부터 시작하여 N-1까지 가면서
		// 해당 부분집합(i의 값 자체가 부분집합임)이
		// 어떤 index의 원소를 가지고 있는 확인하게 된다.
		for (int j = 0; j < N; j++) {
			// 만약 속해있다면 값을 더해주면 된다.
			if (i & (1 << j))
				sum += arr[j];
		}
		if (sum == S)
			ans++;
	}

	cout << ans;
	return 0;
}