#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

long long minDigit(long long a) {
	long long ans;
	char b = '9';
	string str = to_string(a);
	for (int i = 0; i < str.length(); i++) {
		if (b > str[i]) {
			b = str[i];
		}
	}
	char aa[2];
	aa[0] = b;
	aa[1] = '\0';
	ans = atoll(aa);
	return ans;
}

long long maxDigit(long long a) {
	long long ans;
	char b = '0';
	string str = to_string(a);
	for (int i = 0; i < str.length(); i++) {
		if (b < str[i]) {
			b = str[i];
		}
	}
	char aa[2];
	aa[0] = b;
	aa[1] = '\0';
	ans = atoll(aa);
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long a, K;
		cin >> a >> K;

		for (int j = 1; j < K; j++) {
		//	cout << a << " " << minDigit(a) << " " << maxDigit(a) << '\n';
			long long b = minDigit(a);
			if (b == 0) break;
			a = a + minDigit(a) * maxDigit(a);
		}
		cout << a << "\n";
	}
	return 0;
}
