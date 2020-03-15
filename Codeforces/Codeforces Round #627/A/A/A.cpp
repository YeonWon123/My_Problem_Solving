#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int a[100];
int odd, even;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		odd = 0; even = 0;
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> a[j];
			if (a[j] % 2 == 0) {
				odd++;
			}
			else {
				even++;
			}
		}

		if (odd == 0 || even == 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

		
	}

	return 0;
}