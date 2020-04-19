#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long X[1000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, N;
	long long D, min_v, temp, temp2;
	cin >> T;
	for (int i = 0; i < T; i++) {
		min_v = 9999999999999;

		cin >> N >> D;
		for (int j = 0; j < N; j++) {
			cin >> X[j];
		}

		for (int j = N - 1; j > -1; j--) {
			temp = D / X[j] * X[j];
			if (temp < min_v) {
				min_v = temp;
			}
			else {
				while (temp > min_v) {
					temp = temp - X[j];
				}
				min_v = temp;
			}

		}

		cout << "Case #" << i + 1 << ": " << min_v << "\n";
	}

	return 0;
}