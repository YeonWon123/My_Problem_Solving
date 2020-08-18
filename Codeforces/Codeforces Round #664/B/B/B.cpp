#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, sx, sy, i, j, sw1 = 0, sw2 = 0;
	cin >> n >> m >> sx >> sy;

	cout << sx << " " << sy << "\n";

	// �ڽ��� �� �����
	for (i = 1; i <= m; i++) {
		if (i != sy) {
			cout << sx << " " << i << "\n";
		}
	}

	if (sy == m) {
		if (sx != n) {
			// �� ������ �����
			cout << sx + 1 << " " << sy - 1 << "\n";
			for (i = 1; i <= m; i++) {
				if (i != sy - 1) {
					cout << sx + 1 << " " << i << "\n";
				}
			}
			sw1 = 1;
		}
		else {
			// ������ �����
			cout << 1 << " " << sy - 1 << "\n";
			for (i = 1; i <= m; i++) {
				if (i != sy - 1) {
					cout << 1 << " " << i << "\n";
				}
			}
			sw2 = 1;
		}
	}

	// ���� �� �����
	int sw = 1;
	for (i = sx + 1 + sw1; i <= n; i++) {
		if (sw == 0) {
			for (j = 1; j <= m; j++) {
				cout << i << " " << j << "\n";
			}
			sw = 1;
		}
		else {
			for (j = m; j > 0; j--) {
				cout << i << " " << j << "\n";
			}
			sw = 0;
		}
	}

	// ���������� �� �����
	for (i = 1 + sw2; i <= sx - 1; i++) {
		if (sw == 0) {
			for (j = 1; j <= m; j++) {
				cout << i << " " << j << "\n";
			}
			sw = 1;
		}
		else {
			for (j = m; j > 0; j--) {
				cout << i << " " << j << "\n";
			}
			sw = 0;
		}
	}

	return 0;
}