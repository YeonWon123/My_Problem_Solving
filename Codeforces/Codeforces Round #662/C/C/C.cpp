#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int counts[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, n, a, pair_c, min_c;
	cin >> T;
	while (T--) {
		memset(counts, 0, sizeof(counts));
		pair_c = 0;
		min_c = 1000000001;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a;
			counts[a]++;
		}

		for (int i = 1; i <= n; i++) {
			if (counts[a] > 1) {
				pair_c++;
				min_c = min(min_c, counts[a]);
			}
		}
		cout << n / min_c << "\n";
	}
}