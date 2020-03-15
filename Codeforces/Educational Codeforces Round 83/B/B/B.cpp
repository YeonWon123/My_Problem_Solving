#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int a[100];

bool desc(int a, int b) {
	return a > b;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(a, 0, sizeof(a));

		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		sort(a, a + n, desc);

		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}