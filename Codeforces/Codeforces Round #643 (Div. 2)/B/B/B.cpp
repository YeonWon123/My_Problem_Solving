// Greedy ����
// inexperience�� ���� �ͺ��� ������ ��, ä�������� ����̴�.

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

		// ���� ��� ��
		int now = 1;
		int ans = 0;
		for (int j = 0; j < n; j++) {
			// ���� ��� ���� �����ϸ� �׷��� �ϳ� ����
			if (now >= arr[j]) {
				ans++;
				now = 1;
			}
			else {
				// �׷��� ���ϸ� ��� ������ ������ ����� �߰���.
				// �̶� ���� ū ����� �������� �ؾ� �ϴµ� arr[j]�� ���ϸ鼭 ��.
				now++;
			}
		}
		cout << ans << "\n";
	}


	return 0;
}