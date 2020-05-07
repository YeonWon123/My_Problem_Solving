#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

long long two[31];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	two[0] = 1;
	for (int i = 1; i <= 30; i++) {
		two[i] = two[i-1] * 2;
	}

	int T;
	cin >> T;
	int n;
	for (int i = 0; i < T; i++) {
		cin >> n;
		long long ans1 = 0;
		long long ans2 = 0;
		int temp = 1;
		for (int i = 1; i <= n; i++) {
			temp *= 2;
			if (n / 2 > i) {
				ans1 += two[i];
			}
			else if (i != n) {
				ans2 += two[i];
			}
			else
				ans1 += two[i];
		}
		cout << ans1 - ans2 << "\n";
	}

	return 0;
}