#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int counts[51];
int ans[101];
int max_counts = 0;

int main(void)
{
	int t, n, w;
	cin >> t;
	while (t--) {
		memset(counts, 0, sizeof(counts));
		memset(ans, 0, sizeof(ans));
		max_counts = 0;

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> w;
			counts[w]++;
		}

		// 나올 수 있는 조합을 따져서 누적시킴
		for (int i = 1; i <= 50; i++) {
			if (counts[i] == 0) continue;
			for (int j = i; j <= 50; j++) {
				if (counts[j] == 0) continue;

				if (i != j) {
					ans[i + j] += min(counts[i], counts[j]);
				}
				else {
					ans[i + i] += counts[i] / 2;
				}
			}
		}

		// 최댓값을 골라보자
		for (int i = 2; i <= 100; i++) {
			max_counts = max(ans[i], max_counts);
		}

		cout << max_counts << "\n";
	}
	
}