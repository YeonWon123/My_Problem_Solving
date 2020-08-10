#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	long long n;
	long long ans;
	while (T--) {
		cin >> n;
		if (n % 2 == 0) {
			cout << (n + 2) / 2 << "\n";
		}
		else {
			cout << (n + 1) / 2 << "\n";
		}
	}

	return 0;
}