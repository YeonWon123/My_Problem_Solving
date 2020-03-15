#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int temp;
		int sw = 0;
		int odd = 0;
		int odd_pos = 0;
		for (int j = 0; j < n; j++) {
			cin >> temp;

			if (sw == 0) {
				// ¦���� ������ �װ� ���
				if (temp % 2 == 0) {
					cout << 1 << "\n" << j + 1 << "\n";
					sw = 1;
				}
				// Ȧ���� 2�� ������ �װ� ���ؼ� ���
				else if (odd == 0) {
					odd++;
					odd_pos = j + 1;
				}
				else {
					cout << 2 << "\n" << odd_pos << " " << j + 1 << "\n";
					sw = 1;
				}
			}
		}

		// Ȧ���� 1���̰� ¦���� ������ -1 ���
		if (sw == 0) {
			cout << -1 << "\n";
		}
	}

	return 0;
}