#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	int n, k, a, b;
	int ans;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		a = k / (n - 1);
		b = k % (n - 1);

		if (b == 0) {
			a--;
			b = n-1;
		}

		cout << n * a + b << "\n";
	}

	return 0;
}