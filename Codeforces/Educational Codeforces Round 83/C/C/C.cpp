#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

long long a[30] = { 0 };
int counts[1000] = { 0 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(counts, 0, sizeof(counts));

		int n, k;
		cin >> n >> k;
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}

		sort(a, a + n);

		int sw = 0;
		long long temp = 0;
		for (int i = 0; i < n; i++) {
			int t_counts = 0;

		//	cout << "지금은 " << a[i] << " 할 차례" << endl;
			if (a[i] == 0) continue;
			else if (i != 0 && a[i] == a[i - 1]) {
				sw = 1; break;
			}
			
			// 일단 k로 나눈다.
			temp = a[i];
			while (temp % k == 0 && temp != 1) {
				temp = temp / k;
				t_counts++;
			}

			if (temp == 1) {
		//		cout << "초탄 : " << t_counts << endl;
				counts[t_counts]++;
				if (counts[t_counts] != 1) {
					sw = 1;
					break;
				}
				continue;
			}
			else {
			THIS:
		//		cout << "계속시도: " << t_counts << endl;

				counts[t_counts]++;
				if (counts[t_counts] != 1) {
					sw = 1;
					break;
				}

				temp = temp - 1;
				while (temp % k == 0 && temp != 1) {
					temp = temp / k;
					t_counts++;
				}

				if (temp == 1) {
		//			cout << t_counts << endl;

					counts[t_counts]++;
					if (counts[t_counts] != 1) {
						sw = 1;
						break;
					}
					else
						continue;
				}
				else {
 					goto THIS;
				}
			}
		}
		
	//	for (int i = 0; i < 100; i++) {
	//		cout << "counts[" << i << "] : " << counts[i] << endl;
	//	}

		if (sw == 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

	}

	return 0;
}