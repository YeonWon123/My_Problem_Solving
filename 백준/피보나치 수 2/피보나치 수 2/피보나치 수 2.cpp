#include <iostream>
using namespace std;

long long arr[3] = { 0, };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= n; i++) {
		if (i % 3 == 2)
			arr[2] = arr[1] + arr[0];
		else if (i % 3 == 1)
			arr[1] = arr[0] + arr[2];
		else
			arr[0] = arr[1] + arr[2];
	}

	cout << arr[n % 3];
	return 0;
}