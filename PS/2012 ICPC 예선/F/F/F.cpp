#include <iostream>
#include <algorithm>
using namespace std;

int arr[100];
int res[100];
pair<int, int> res2[100];
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	int n, sw;
	for (int i = 0; i < T; i++) {
		sw = 0;
		// res 초기화
		for (int j = 0; j < 100; j++) {
			res[j] = 1;
			res2[j].first = 1;
			res2[j].second = j + 1;
		}
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
			if (arr[j] > j) sw = 1;
		}

		if (sw == 1) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			for (int j = 1; j <= n; j++) {
				// arr[j]+1 보다 같거나 큰거는 전부 +1 하면 됨
				res[j] = arr[j] + 1;
				res2[j].first = arr[j] + 1;
				for (int p = 0; p < j; p++) {
					if (res[p] >= res[j]) {
						res[p]++;
						res2[p].first++;
					}
				}
			}
			/*
			for (int j = 0; j < n; j++) {
				cout << res2[j].first << " " << res2[j].second << "\n";
			}
			*/
			sort(res2, res2 + n);
			/*
			cout << "sort결과" << endl;
			for (int j = 0; j < n; j++) {
				cout << res2[j].first << " " << res2[j].second << "\n";
			}

			cout << "정답" << endl; */
			for (int j = 0; j < n; j++) {
				res[res2[j].second] = j + 1;
			}
			
			for (int j = 1; j <= n; j++) {
				cout << res[j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}