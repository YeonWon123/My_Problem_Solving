// 반례 : 
//	6 1
//	111001
// 1이 나와야 하지만, 2가 나와서 오류!

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int ans[100000];
string str2[100000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	int n, k;
	int i = 0;
	for (i = 0; i < t; i++) {
		string str;
		cin >> n >> k >> str;

		if (n == 1) {
			cout << 0 << "\n";
			continue;
		}

		if (k == 1) {
			int one = 0, zero = 0;
			int sw = 0;
			int start = 0;
			int end = 0;
			for (int j = 0; j < n; j++) {
				if (str[j] == '1') {
					if (sw == 0) {
						start = j;
						end = j;
						sw = 1;
					}
					else {
						end = j;
					}
					one++;
				}
				else if (sw == 1) {
					zero++;
				}
			}
			if (n - 1 > end) {
				zero -= n - 1 - end;
			}

			if (one == 0) cout << 0 << "\n";
			else cout << min(one - 1, zero) << "\n";
			continue;
		}

		memset(ans, 0, sizeof(ans));
		for (int j = 0; j < k; j++) {
			str2[j] = "";
		}

		int ii = 0;
		for (ii = 0; ii < k; ii++) {
			int start = -1;
			int end = -1;
			int j = 0;
			int sw = 0;
			for (j = 0; ii + k * j < n; j++) {
				if (str[ii + k * j] == '1' && sw == 0) {
					sw = 1;
					start = ii + k * j;
				}
			}
			j--;
			if (start != -1) {
				for (; j >= 0; j--) {
					if (str[ii + k * j] == '1') {
						end = ii + k * j;
						break;
					}
				}
			}

			for (j = 0; j < start; j++) {
				if (str[j] == '1') {
					ans[ii]++;
				}
			}

			if (start != -1) {
				for (j = start; j <= end; j++) {
					if ((j - start) % k == 0) {
						if (str[j] == '0') {
							ans[ii]++;
						}
					}
					else {
						if (str[j] == '1')
							ans[ii]++;
					}
				}
			}

			for (j = end + 1; j < n; j++) {
				if (str[j] == '1') {
					ans[ii]++;
				}
			}
		}

		int answer = 99999999;
		for (ii = 0; ii < k; ii++) {
			answer = min(answer, ans[ii]);
		}
		cout << answer << "\n";
	}

	return 0;
}