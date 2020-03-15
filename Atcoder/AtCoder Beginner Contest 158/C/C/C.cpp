#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int A, B;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B;
	for (int X = 1; X < 10000; X++) {
		int a = (X * 0.08);
		int b = (X * 0.1);
		if (A == a && B == b) {
			cout << X;
			return 0;
		}
	}
	cout << -1;
	return 0;
}