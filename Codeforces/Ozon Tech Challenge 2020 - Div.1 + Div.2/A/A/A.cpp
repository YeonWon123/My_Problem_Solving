#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	int p;

	for (int i = 0; i < t; i++) {
		int a[100];
		int b[100];

		cin >> p;
		for (int j = 0; j < p; j++) {
			cin >> a[j];
		}

		for (int j = 0; j < p; j++) {
			cin >> b[j];
		}

		sort(a, a + p);
		sort(b, b + p);

		for (int j = 0; j < p; j++) {
			cout << a[j] << " ";
		}

		cout << "\n";

		for (int j = 0; j < p; j++) {
			cout << b[j] << " ";
		}

		cout << "\n";
	}

	return 0;
}