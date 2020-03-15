#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int last;
int a[5001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, temp, sw;
	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(a, 0, sizeof(a));
		sw = 0;
		last = -1;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> temp;
			a[temp]++;
			if ((j != 0) && (a[temp] > 1) && (temp != last)) {
				sw = 1;
			}
			else if (a[temp] > 2) {
				sw = 1;
			}

			last = temp;
		}

		if (sw == 1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}


	}

	return 0;
}