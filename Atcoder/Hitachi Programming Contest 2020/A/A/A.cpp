#include <iostream>
using namespace std;

string s;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	if (s.size() % 2 == 1) {
		cout << "No";
		return 0;
	}

	for (int i = 0; i < s.size(); i++) {
		if ((i % 2 == 0 && s[i] != 'h') || (i % 2 == 1 && s[i] != 'i')) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}