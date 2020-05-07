#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
vector<int> arr[26];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	cin >> s;

	for (int i = 0; i < n; i++) {		
		arr[(int)(s[i] - 'a')].push_back(i);
	}
	
	for (int i = 25; i > 0; i--) {
		for (int j = 0; j < arr[i].size(); j++) {
			int index = arr[i][j];
			int index1 = index - 1;
			int index2 = index + 1;

			while (index1 != -1 && s[index1] == '0') {
				index1 = index1 - 1;
			}

			while (index2 != n && s[index2] == '0') {
				index2 = index2 + 1;
			}

			if (((index1 != -1) && ((s[index] - s[index1]) == 1)) || ((index2 != n) && ((s[index] - s[index2]) == 1))) {
				s[index] = '0';
			}
		}

		for (int j = arr[i].size() - 1; j > -1; j--) {
			int index = arr[i][j];
			int index1 = index - 1;
			int index2 = index + 1;

			while (index1 != -1 && s[index1] == '0') {
				index1 = index1 - 1;
			}

			while (index2 != n && s[index2] == '0') {
				index2 = index2 + 1;
			}

			if (((index1 != -1) && ((s[index] - s[index1]) == 1)) || ((index2 != n) && ((s[index] - s[index2]) == 1))) {
				s[index] = '0';
			}
		}

	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] != '0') {
			answer++;
		}
	}

	cout << n - answer;
	return 0;
}