#include <iostream>
#include <cstring>
using namespace std;

int m[1000000] = { 0 }; // minus
int p[1000000] = { 0 }; // plus
int zero = 0;			// 0

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp > 0)
			p[temp - 1] = 1;
		else if (temp < 0)
			m[(temp * -1) - 1] = 1;
		else
			zero = 1;
	}
	
	for (int i = 999999; i > -1; i--) {
		if (m[i] == 1) {
			cout << -1 * (i + 1) << '\n';
		}
	}

	if (zero == 1)
		cout << 0 << '\n';

	for (int i = 0; i < 1000000; i++) {
		if (p[i] == 1) {
			cout << i + 1 << '\n';
		}
	}

	return 0;
}