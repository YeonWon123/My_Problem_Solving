#include <iostream>
#include <algorithm>
using namespace std;

string answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		int counts = 1;
		int size;
		cin >> size;
		string s;
		s.reserve(size);
		cin >> s;
		answer = s;
		for (int j = 0; j < size; j++) {
			string temp = s;
			for (int i = 0; i < size - j; i++) {
				reverse(temp.begin() + i, temp.begin() + i + j + 1);
			}
			cout << j + 1 << "번째 경우 : " << temp << "\n";
			if (answer > temp) {
				answer = temp;
				counts = j + 1;
			}
		}

		cout << answer << "\n" << counts << "\n";
	}
	return 0;
}
