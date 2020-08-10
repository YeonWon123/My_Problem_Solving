#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

char res[50][50];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);

	int T, N;
	char c;
	cin >> T;
	for (int p = 1; p <= T; p++) {
		cin >> N;
		memset(res, 'Y', sizeof(res));
		// I[i]
		for (int i = 0; i < N; i++) {
			cin >> c;
			if (c == 'N') {
				for (int j = 0; j < i; j++) {
					for (int k = i; k < N; k++) {
						res[j][k] = 'N';
					}
				}

				for (int j = i+1; j < N; j++) {
					for (int k = 0; k < i; k++) {
						res[j][k] = 'N';
					}
				}

				for (int j = 0; j < N; j++) {
					if (i != j) {
						res[j][i] = 'N';
					}
				}
			}
		}

		// O[i]
		for (int i = 0; i < N; i++) {

			cin >> c;
			if (c == 'N') {
				for (int j = 0; j <= i; j++) {
					for (int k = i+1; k < N; k++) {
						res[j][k] = 'N';
					}
				}

				for (int j = i; j < N; j++) {
					for (int k = 0; k < i; k++) {
						res[j][k] = 'N';
					}
				}

				for (int j = 0; j < N; j++) {
					if (i != j) {
						res[i][j] = 'N';
					}
				}
			}
		}

		// print
		cout << "Case #" << p << ":\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << res[i][j];
			}
			cout << "\n";
		}
	}
}