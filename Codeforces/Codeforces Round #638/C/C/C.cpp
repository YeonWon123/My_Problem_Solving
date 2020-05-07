#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

char str[200000];
char b[200000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	int n, k;
	for (int i = 0; i < T; i++) {
		cin >> n >> k;
		cin >> str;
		sort(str, str + n);

		// k�� 1�� ��� ���� ó��
		if (k == 1) {
			cout << str << "\n";
			continue;
		}

		// �տ� k���� �� ������ ����, �ٸ��� �ٷ� ������ ó����
		char temp = str[0];
		int j;
		for (j = 1; j < k; j++) {
			if (str[j] != temp) {
				cout << str[k - 1] << "\n";
				break;
			}
		}
		if (j !=  ) continue;

		cout << str[0];
		
		int p = j;
		if (j == n) {
			cout << "\n";
			continue;
		}

		if (j + j > n) {
			cout << str[j] << "\n";
			continue;
		}

		for (p = j; p < n - 1; p++) {
			if (str[p] < str[p + 1]) {
				break;
			}
		}

		if (p != n - 1) {
			for (int q = k; q < n; q++) {
				cout << str[q];
			}
			cout << "\n";
			continue;
		}

		// �� ���� �ڿ��� ��� ������ �ǹ���
		// ���� ���� / ������ �� ���� �� ������1
		for (int q = 0; q < (n - j) / k; q++) {
			cout << str[p];
		}
		if ((n - j) / k != (n - j) / (double)k) {
			cout << str[p];
		}
		cout << "\n";

	}
	return 0;
}