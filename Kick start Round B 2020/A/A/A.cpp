#include <iostream>
#include <cstring>
using namespace std;

int H[100];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, N, peak;
	cin >> T;
	for (int i = 0; i < T; i++) {
		memset(H, 0, sizeof(H));
		peak = 0;

		cin >> N;
		int updown = 0;
		for (int j = 0; j < N; j++) {
			cin >> H[j];

			if (j > 1) {
				if (H[j - 1] > H[j] && H[j - 1] > H[j - 2]) {
					peak++;
				}
			}

		}

		cout << "Case #" << i + 1 << ": " << peak << "\n";
	}

	return 0;
}