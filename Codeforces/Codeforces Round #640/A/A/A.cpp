#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;

		if (b < 10) {
			cout << 1 << "\n" << b << "\n";
			continue;
		}
		else if (b < 100) {
			int c = b / 10;
			int d = b % 10;
			if (d == 0) {
				cout << 1 << "\n" << b << "\n";
			}
			else {
				cout << 2 << "\n" << c*10 << " " << d << "\n";
			}
		}
		else if (b < 1000) {
			int c = b / 100;
			int d = (b - (b / 100) * 100) / 10;
			int e = b % 10;
			if (d == 0 && e == 0) {
				cout << 1 << "\n" << b << "\n";
			}
			else if (d != 0 && e != 0) {
				cout << 3 << "\n" << c*100 << " " << d*10 << " " << e << "\n";
			}
			else {
				cout << 2 << "\n" << c*100 << " ";
				if (d != 0) {
					cout << d*10 << "\n";
				}
				else if (e != 0) {
					cout << e << "\n";
				}
			}
		}
		else if (b < 10000) {
			
			int c = b / 1000;
			int c_temp = b - (b / 1000 * 1000);
			int d = c_temp / 100;
			int e = c_temp % 100 / 10;
			int f = b % 10;			

			int arr[4];
			arr[0] = c;
			arr[1] = d;
			arr[2] = e;
			arr[3] = f;

			if (c == 0 && d == 0 && e == 0 && f == 0) {
				cout << 1 << "\n" << b << "\n";
			}
			else if (c != 0 && d != 0 && e != 0 && f != 0) {
				cout << 4 << "\n" << c * 1000 << " " << d * 100 << " " << e * 10 << " " << f << "\n";
			}
			else {
				int ans = 0;
				for (int i = 0; i < 4; i++) {
					if (arr[i] != 0) {
						ans++;
					}
				}
				cout << ans << "\n";
				int pp = 1000;
				for (int i = 0; i < 4; i++) {
					if (arr[i] != 0) {
						cout << arr[i] * pp << " ";
					}
					pp = pp / 10;
				}
				cout << "\n";
			}
		}
		else {
			cout << 1 << "\n" << 10000 << "\n";
		}
	}
}