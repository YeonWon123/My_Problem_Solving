#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int arr[200000];
int ind[200000] = { 0 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		memset(ind, 0, sizeof(ind));
		int n, sw = 0;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
			if (sw == 0) {
				arr[j] = arr[j] % n;
				if (arr[j] < 0) {
					arr[j] = n + arr[j];
				}
				arr[j] += j;
				arr[j] %= n;
				ind[arr[j]]++;
				if (ind[arr[j]] > 1) {
					sw = 1;
				}
			}
		}

		if (n == 1) {
			cout << "YES\n";
		}
		else if (sw == 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}