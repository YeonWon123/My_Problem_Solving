#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int a[200000];
unsigned long long answer = 1;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	int ans;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 1; j <= i; j++) {
			ans = abs(a[i] - a[i - j]);
			while (ans >= m) {
				ans -= m;
			}
			answer = answer * ans;
		}
	}

	while (answer >= m) {
		answer -= m;
	}

	cout << answer;
	return 0;
}