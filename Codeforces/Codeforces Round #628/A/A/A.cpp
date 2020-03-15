#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		cout << 1 << " " << n - 1 << "\n";
	}

	return 0;
}