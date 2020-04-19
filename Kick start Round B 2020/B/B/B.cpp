#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int X[1000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, N;
	int D, min_v, temp, p;
	cin >> T;
	for (int i = 0; i < T; i++) {
		min_v = 999;

		cin >> N >> D;
		for (int j = 0; j < N; j++) {
			cin >> X[j];
		}

		for (int j = N - 1; j > -1; j--) {
			temp = D - (D % X[j]);
			if (min_v > temp) {
				min_v = temp;
			}
			else if (min_v < temp) {
				p = ((temp - min_v) / X[j]) + 1;
				temp = temp - (X[j] * p);
				min_v = temp;
			}
			cout << temp << endl;
		}

		cout << "Case #" << i + 1 << ": " << min_v << "\n";
	}

	return 0;
}