#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	int n, m;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		if (n == 1) {
			cout << 0 << "\n";
			continue;
		}
		else if (n == 2) {
			cout << m << "\n";
			continue;
		}
		else {
			cout << 2 * m << "\n";
			continue;
		}
	}

	return 0;
}