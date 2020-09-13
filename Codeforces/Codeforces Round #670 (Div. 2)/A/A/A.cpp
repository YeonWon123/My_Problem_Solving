#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int a[101];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, temp;
	cin >> t;
	while (t--) {
		cin >> n;
		memset(a, 0, sizeof(a));
		
		for (int i = 0; i < n; i++) {
			cin >> temp;
			a[temp]++;
		}

		int sw = 0; int ans = 0;
		for (int i = 0; i <= 100; i++) {
			if (a[i] == 0) {
				if (sw == 0) {
					ans += i * 2;
					sw = 2;
				}
				else if (sw == 1) {
					ans += i;
					sw = 2;
				}
			}
			else if (a[i] == 1) {
				if (sw == 0) {
					ans += i;
					sw = 1;
				}
			}
			if (sw == 2) break;
		}

		cout << ans << "\n";
	}
}