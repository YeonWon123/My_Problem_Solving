#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		if (a % b == 0) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}