#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	int n, temp, a, b;
	for (int i = 0; i < t; i++) {
		deque<int> input;
		a = 0, b = 0;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> temp;
			input.push_back(temp);
		}

		int eat = 0;
		int now;
		int counts = 0;
		while (!input.empty()) {

			// Alice Time
			now = 0;
			while (now <= eat && !input.empty()) {
				now += input.front();
				input.pop_front();
			}
			eat = now;
			a += now;
			counts++;

			if (input.empty()) break;

			// Bob Time
			now = 0;
			while (now <= eat && !input.empty()) {
				now += input.back();
				input.pop_back();
			}
			eat = now;
			b += now;

			counts++;
		}
		cout << counts << " " << a << " " << b << "\n";
	}

	return 0;
}