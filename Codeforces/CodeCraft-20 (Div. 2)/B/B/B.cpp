#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		int counts = 1;
		int alphabet[26] = { 0 };
		vector<int> alphabet_pos[26];

		int size;
		cin >> size;
		string s;
		s.reserve(size);
		cin >> s;

		if (size == 1) {
			cout << s << "\n" << 1 << "\n";
			continue;
		}

		char last_alpha = '0';
		for (int j = 0; j < size; j++) {
			if (last_alpha != s[j]) {
				last_alpha = s[j];
				alphabet[((int)s[j] - 'a')]++;
				alphabet_pos[((int)s[j] - 'a')].push_back(j);
			}
		}

		string answer = s;

		for (int j = 0; j < size; j++) {
			string temp = s;
			for (int i = 0; i < size - j; i++) {
				reverse(temp.begin() + i, temp.begin() + i + j + 1);
			}
			if (answer > temp) {
				answer = temp;
				counts = j + 1;
			}
		}

		cout << s << "\n" << counts << "\n";
	}
	return 0;
}
