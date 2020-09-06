#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long T, a, b, x, y, n;
	cin >> T;
	while (T--) {
		cin >> a >> b >> x >> y >> n;
		long long ans = LLONG_MAX;
		long long now;
		// 왼쪽 max랑 오른쪽 max를 따로 구하자
		int leftmax = min(a - x, n);
		int rightmax = min(b - y, n);
		if (leftmax + rightmax <= n) {
			cout << (a - leftmax) * (b - rightmax) << "\n";
		}
		else {
			long long aa, bb;
			aa = (a - leftmax) * (b - (n - leftmax));
			bb = (a - (n - rightmax)) * (b - rightmax);
			cout << min(aa, bb) << "\n";
		}
	}

	return 0;
}