// ���� : 6 -2 4 -3 10 -15
// ���� : 0�� ���;� ��

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	int n;
	long long a;
	long long temp = 0;
	long long ans;
	while (T--) {
		cin >> n;

		ans = 0;
		temp = 0;

		for (int i = 0; i < n; i++) {
			cin >> a;
			// ���� �������� �����̰� �ڿ��� ����� ��� - �̶��� �ٲ�
			// ���� ������ : temp

			if (temp < 0 && a > 0) {
				ans += temp * -1;
				temp = a;
			}
			else {
				temp += a;
				
			}
		}

		cout << ans << "\n";
	}

	return 0;
}