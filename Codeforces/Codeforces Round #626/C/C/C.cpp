#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

char s[1000001];
int a[1000001];

int now = 0;
int last_zero = -1;

int answer = 0;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	if (n % 2 == 1) {
		cin >> s;
		cout << -1;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> s[i];
		if (s[i] == '(') {
			now++;
			a[i] = now;
		}
		else {
			now--;
			a[i] = now;
		}

		if (a[i] == 0) {
			if (a[i - 1] < 0) {
				answer += i - last_zero;
			}

			last_zero = i;
		}
	}


	if (now != 0) {
		cout << -1 << "\n";
	}
	else {
		cout << answer << "\n";
	}

	return 0;
}