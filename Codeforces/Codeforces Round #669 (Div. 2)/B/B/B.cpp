#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 나머지 연산을 이용한 GCD 연산
int GCD(int u, int v) {
	int t;
	while (v) {
		t = u % v;
		u = v;
		v = t;
	}

	return u;
}

int ans[1000];
int a[1000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, n, max_value, temp, temp2, index;
	cin >> T;
	while (T--) {
		max_value = -1;
		index = -1;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (max_value < a[i]) {
				max_value = a[i];
				index = i;
			}
		}

		ans[0] = max_value;
		a[index] = -1;

		for (int j = 1; j < n; j++) {
			temp = 0;
			temp2 = 0;
			index = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] != -1) {
					temp2 = GCD(max_value, a[i]);
					if (temp2 == max_value) {
						ans[j] = a[i];
						a[i] = -1;
						j++;
					}
					else if (temp < temp2) {
						temp = temp2;
						index = i;
					}
				}
			}

			ans[j] = a[index];
			max_value = temp;
			a[index] = -1;
		}

		for (int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}


	return 0;
}