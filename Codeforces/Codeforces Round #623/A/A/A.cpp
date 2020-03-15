#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	int x, y, a, b;
	int a1, a2, a3, a4;
	int answer;
	for (int i = 0; i < t; i++) {
		cin >> x >> y >> a >> b;
		a1 = a * y;
		a2 = (x - (a + 1)) * y;
		a3 = x * b;
		a4 = x * (y - (b + 1));
	//	cout << a1 << " " << a2 << " " << a3 << " " << a4 << "\n";
		answer = max(a1, max(a2, max(a3, a4)));
		cout << answer << "\n";
	}

	return 0;
}