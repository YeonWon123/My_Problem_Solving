#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int arr[200] = { 0, };
int real[200] = { 0, };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, k, temp;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		int s = 0;
		memset(arr, 0, sizeof(arr));
		memset(real, 0, sizeof(real));
		for (int j = 0; j < n; j++) {
			cin >> temp;
			if (arr[temp] == 0) {
				real[s] = temp;
				s++;
				arr[temp] = 1;
			}
		}
		if (s > k) {
			cout << -1 << "\n";
			continue;
		}
		else {
			cout << k * n << "\n";
			for (int j = 0; j < n; j++) {
				for (int p = 0; p < k; p++) {
					if (real[p] == 0) {
						temp = 1;
						while (arr[temp] != 0) {
							temp++;
						}
						arr[temp] = 1;
						real[p] = temp;
					}
					cout << real[p] << " ";
				}
			}
			cout << "\n";
		}
	}

	return 0;
}