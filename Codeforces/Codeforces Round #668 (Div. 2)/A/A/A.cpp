#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int p[100];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	int n;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		for (int i = n - 1; i > -1; i--) {
			cout << p[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}