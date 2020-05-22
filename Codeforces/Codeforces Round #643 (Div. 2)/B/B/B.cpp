// Greedy 문제
// inexperience가 작은 것부터 정렬한 뒤, 채워나가는 방식이다.

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int arr[200001] = { 0 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, temp, ans = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}

		sort(arr, arr + n);

		// 현재 사람 수
		int now = 1;
		int ans = 0;
		for (int j = 0; j < n; j++) {
			// 현재 사람 수로 만족하면 그룹이 하나 생김
			if (now >= arr[j]) {
				ans++;
				now = 1;
			}
			else {
				// 그렇지 못하면 계속 만족할 때까지 사람을 추가함.
				// 이때 가장 큰 사람을 기준으로 해야 하는데 arr[j]랑 비교하면서 함.
				now++;
			}
		}
		cout << ans << "\n";
	}


	return 0;
}