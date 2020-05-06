#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// 소수 구하는 함수
bool isNumber(int a) {
	if (a == 1) return false;
	if (a == 2) return true;

	if (a % 2 == 0) return false;
	for (int i = 3; i <= sqrt(a); ) {
		if (a % i == 0)
			return false;
		i = i + 2;
	}
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, temp, ans = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (isNumber(temp))
			ans++;
	}
	cout << ans;
	return 0;
}