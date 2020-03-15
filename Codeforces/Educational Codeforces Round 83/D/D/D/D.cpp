#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	if (n % 2 != 0) {
		n = n / 2 + 1;
	}
	else {
		n = n / 2;
	}

	// 증가하게 만들기
	// nCr을 구하면 됨 (여기서는 mCn)

	if (m - n < n) {
		n = m - n;
	}

	cout << "m : " << m << ", n : " << n << endl;

	long long up = m;
	long long down = n;
	long long ss = n;
	long long answer = 1;

	for (int i = 1; i < ss; i++) {
		if (i == 1) {
			m--;
			if (up % n == 0)
				answer = (((long long)up / n) * ((long long)m)) % 998244353;
			else
				answer = ((long long)up * (((long long)m) / n)) % 998244353;
		}
		else {
			m--; n--;
			if (answer % n == 0) {
				answer = ((answer / n) * m) % 998244353;
			}
			else {
				answer = (answer * (m / n)) % 998244353;
			}
		}
	}

	cout << answer % 998244353;
	
	return 0;
}