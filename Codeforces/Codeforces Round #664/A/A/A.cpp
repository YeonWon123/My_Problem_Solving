#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, r, g, b, w;
	cin >> t;
	while (t--) {
		int p = 0; int o = 0;
		int zero = 0;
		cin >> r >> g >> b >> w;
		if (r % 2 == 0) o++;
		else p++;
		if (g % 2 == 0) o++;
		else p++;
		if (b % 2 == 0) o++;
		else p++;
		if (w % 2 == 0) o++;
		else p++;

		if (r == 0) zero++;
		if (g == 0) zero++;
		if (b == 0) zero++;

		if (o == 2 && p == 2) {
			cout << "No\n";
		}
		else if (p == 3 && zero != 0) {
			cout << "No\n";
		}
		else cout << "Yes\n";
		
	}

	return 0;
}