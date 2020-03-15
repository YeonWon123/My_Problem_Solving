#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		set<int> a;

		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			a.insert(temp);
		}

		cout << min(n, (int)a.size()) << "\n";
	}

	return 0;
}