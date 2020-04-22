#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	
	int n, sum1, sum2, i;
	while (t--) {
		cin >> n;
		if ((n / 2) % 2 == 1) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			sum1 = 0;
			sum2 = 0;
			for (i = 1; i <= n / 2; i++) {
				sum1 += (i * 2);
				cout << i * 2 << " ";
			}

			for (int j = 1; j < i-1; j++) {
				sum2 += (j * 2 - 1);
				cout << j * 2 - 1 << " ";
			}

			cout << sum1 - sum2  << "\n";
		}

	}

	return 0;
}