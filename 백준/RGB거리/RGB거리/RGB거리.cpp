#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int DP[1000][3] = { 0, };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int R, G, B;
	for (int i = 0; i < n; i++) {
		cin >> R >> G >> B;
		if (i == 0) {
			DP[0][0] = R;
			DP[0][1] = G;
			DP[0][2] = B;
		}
		else {
			DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + R;
			DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + G;
			DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + B;
		}
	}

	cout << min(DP[n - 1][0], min(DP[n - 1][1], DP[n - 1][2]));
	return 0;
}