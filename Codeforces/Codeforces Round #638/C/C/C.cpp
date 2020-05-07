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

		// k가 1인 경우 먼저 처리
		if (k == 1) {
			cout << str << "\n";
			continue;
		}

		// 앞에 k개가 다 같은지 보자, 다르면 바로 답으로 처리함
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

		// 이 경우는 뒤에가 모두 같음을 의미함
		// 남은 개수 / 나눠야 할 개수 를 시행함1
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