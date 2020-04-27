#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	long long max_v, min_v, res;
	for (int i = 0; i < T; i++) {
		long long x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y) {
			max_v = x;
			min_v = y;
		}
		else {
			max_v = y;
			min_v = x;
		}
		
		long long res1 = min_v * b + (max_v - min_v) * a;
		long long res2 = min_v * a + max_v * a;
		if (res1 > res2) {
			cout << res2 << "\n";
		}
		else
			cout << res1 << "\n";
	}
	return 0;
}