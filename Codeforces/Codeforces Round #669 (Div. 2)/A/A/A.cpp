#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, a;
		int one = 0;
		int zero = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (a == 0) zero++;
			else one++;
		}

		if (zero >= one) {
			cout << zero << "\n";
			for (int i = 0; i < zero; i++) {
				cout << 0 << " ";
			}
			cout << "\n";
		}
		else { // zero < one
			if (one % 2 != 0) {
				one--;
			}
			
			cout << one << "\n";
			for (int i = 0; i < one; i++) {
				cout << 1 << " ";
			}
			cout << "\n";
			
		}
	}


	return 0;
}