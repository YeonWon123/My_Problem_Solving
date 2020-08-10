#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a, b, c, sw = 0;
	cin >> a >> b >> c;

	if (a == b) sw++;
	if (b == c) sw++;
	if (c == a) sw++;
	
	switch (sw) {
	case 3:
		cout << 10000 + a * 1000;
		break;
	case 1:
		if (a == b || a == c) cout << 1000 + a * 100;
		else cout << 1000 + b * 100;
		break;
	case 0:
		sw = max(a, max(b, c));
		cout << sw * 100;
		break;
	}
}