#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string s;
		int ans = 0;
		int index = 0;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'O') {
			 	index++;
				ans += index;
			}
			if (s[j] == 'X') {
				index = 0;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}