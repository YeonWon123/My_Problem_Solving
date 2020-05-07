#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	int n, m;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		if (n == 1 || m == 1) {
			cout << "YES\n";
		}
		else if (n == 2 && m == 2) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}