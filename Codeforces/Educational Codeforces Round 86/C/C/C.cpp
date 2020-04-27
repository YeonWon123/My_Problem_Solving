//#define DEBUG

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// a > b
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

// a > b
int lcm(int a, int b) {
	return (a / gcd(a, b)) * b;
}

int arr[200000] = { 0 };

int main(void)
{
#ifdef DEBUG
	int ams = 0;
	for (int l = 100; l <= 200; l++) {
		//cout << (l % 4) % 6 << " " << (l % 6) % 4 << endl;
		if (((l % 7) % 10) != ((l % 10) % 7)) {
			ams++;
		}
	}
	cout << ams;

	return 0;

#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		memset(arr, 0, sizeof(arr));
		int a, b, q;
		cin >> a >> b >> q;
		
		int sum = 0;
		int lcm_n = lcm(max(a,b), min(a,b));
		for (int j = 1; j <= lcm_n; j++) {
			if (((j % a) % b) != ((j % b) % a)) {
				arr[j]++;
				sum++;
			}
		}

		for (int j = 0; j < q; j++) {
			long long l, r;
			cin >> l >> r;
			long long div1 = l / lcm_n;
			int spa1 = l % lcm_n;
			long long div2 = r / lcm_n;
			int spa2 = r % lcm_n;

			long long full_n = (div2 - div1 - 1) * sum;

			for (int j = lcm_n; j >= spa1; j--) {
				full_n += arr[j];
			}

			for (int j = 1; j <= spa2; j++) {
				full_n += arr[j];
			}

			cout << full_n << " ";
		}
		cout << "\n";
	}
	return 0;
}