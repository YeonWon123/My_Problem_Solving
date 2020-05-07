#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int arr[30000];

int main(void)
{
	int sum = 2;
	int add = 5;
	int i;
	for (i = 0; sum <= 1000000000; i++) {
		arr[i] = sum;
		sum += add;
		add += 3;
	}
	arr[i] = sum;
	i++;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	int n, k, ans;
	for (int j = 0; j < t; j++) {
		ans = 0;
		cin >> n;
		while (true) {
			if (n == 0 || n == 1) {
				cout << ans << "\n";
				break;
			}

			int k = lower_bound(arr, arr + i, n) - arr;
			if (arr[k] == n) {
				cout << ans + 1 << "\n";
				break;
			}
			else {
				int temp = (n / arr[k - 1]);
				ans += temp;
				n = n - (temp * arr[k - 1]);
			}
		}
	}
	return 0;
}