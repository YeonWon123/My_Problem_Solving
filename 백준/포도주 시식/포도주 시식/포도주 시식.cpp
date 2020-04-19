#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

int DP[10000][3] = { 0, };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int bottle;
	for (int i = 0; i < n; i++) {
		cin >> bottle;
		if (i == 0) {
			DP[0][0] = 0;
			DP[0][1] = bottle;
			DP[0][2] = 0;
		}
		else {
			DP[i][0] = DP[i - 1][1] + bottle;
			DP[i][1] = DP[i - 1][2] + bottle;
			DP[i][2] = max(DP[i - 1][0], max(DP[i - 1][1], DP[i - 1][2]));
		}
	}

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < n; i++) {
			cout << setw(5) << DP[i][j] << " ";
		}
		cout << endl;
	}

	cout << max(DP[n - 1][0], max(DP[n - 1][1], DP[n - 1][2]));
	return 0;
}