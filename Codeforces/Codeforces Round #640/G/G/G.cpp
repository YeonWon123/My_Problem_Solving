#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;
		if (n <= 3) {
			cout << "-1" << "\n";
			continue;
		}

		deque<int> a;
		a.push_back(3);
		a.push_back(1);
		a.push_back(4);
		a.push_back(2);

		for (int j = 5; j <= n; j++) {
			if (j % 2 == 1) {
				a.push_back(j);
			}
			else {
				a.push_front(j);
			}
		}

		for (int j = 0; j < n; j++) {
			cout << a.front() << " ";
			a.pop_front();
		}
		cout << "\n";
	}

	return 0;
}