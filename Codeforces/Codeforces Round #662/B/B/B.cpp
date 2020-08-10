#include <iostream>
#include <vector>
using namespace std;

int counts[100001];
int eight = 0;
int four = 0;
int two = 0;

void change(int x, int ch) {
	if (ch == '+') {
		counts[x]++;
		if (counts[x] == 14) {
			two++;
		}
		else if (counts[x] == 12) {
			four++; two--;
		}
		else if (counts[x] == 10) {
			two++;
		}
		else if (counts[x] == 8) {
			eight++; four--; two--;
		}
		else if (counts[x] == 6) {
			two++;
		}
		else if (counts[x] == 4) {
			four++; two--;
		}
		else if (counts[x] == 2) {
			two++;
		}
	}
	else {
		counts[x]--;
		if (counts[x] == 13) {
			two--;
		}
		else if (counts[x] == 11) {
			four--; two++;
		}
		else if (counts[x] == 9) {
			two--;
		}
		else if (counts[x] == 7) {
			eight--; four++; two++;
		}
		else if (counts[x] == 5) {
			two--;
		}
		else if (counts[x] == 3) {
			four--; two++;
		}
		else if (counts[x] == 1) {
			two--;
		}
	}


}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, a, q, x;
	char ch;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		counts[a]++;
	}

	for (int i = 1; i <= 100000; i++) {
		if (counts[i] >= 14) {
			eight++; four++; two++;
		}
		else if (counts[i] >= 12) {
			eight++; four++;
		}
		else if (counts[i] >= 10) {
			eight++; two++;
		}
		else if (counts[i] >= 8) {
			eight++;
		}
		else if (counts[i] >= 6) {
			four++; two++;
		}
		else if (counts[i] >= 4) {
			four++;
		}
		else if (counts[i] >= 2) {
			two++;
		}
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> ch >> x;
		change(x, ch);
		if (eight > 0)					cout << "YES\n";
		else if (four > 1)				cout << "YES\n";
		else if (four > 0 && two > 1)	cout << "YES\n";
		else							cout << "NO\n";
	}

}

