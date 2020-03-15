#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int a[2000];
int b[2000];

string answers = "";

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;
	int pp;
	for (pp = 1; ; pp++) {

		int size = s.length();
		int a_counts = 0;
		int b_counts = 0;

		for (int i = 0; i < size; i++) {
			if (s[i] == '(') {
				a[a_counts] = i + 1;
				a_counts++;
			}
		}

		for (int i = size - 1; i > 0; i--) {
			if (s[i] == ')') {
				b[b_counts] = i + 1;
				b_counts++;
			}
		}

		if ((a_counts == 0 || b_counts == 0) || (a[0] > b[0])) {
			pp--;
			break;
		}
		else {
			int c = 0;
			while (a[c] < b[c] && c < a_counts && c < b_counts) {
				c++;
			}
			// cout << c * 2 << "\n";
			int c2 = c * 2;
			answers += to_string(c2);
			answers += "\n";
			for (int i = 0; i < c; i++) {
			//	cout << a[i] << " ";
				answers += to_string(a[i]);
				answers += " ";
				s.erase(a[i] - i - 1, 1);
			}
			int ii = 0;
			for (int i = c-1; i > -1; i--) {
			//	cout << b[i] << " ";
				answers += to_string(b[i]);
				answers += " ";
			//	cout << s << endl;
			//	cout << b[i] - c - 1 << endl;
				s.erase(b[i] - c - 1 - ii, 1);
				ii++;
			}
		//	cout << "\n";
			answers += "\n";
		}
	}

	if (pp == 0) {
		cout << 0;
		return 0;
	}
	else {
		cout << pp << "\n";
		for (int i = 0; i < answers.size(); i++) {
			cout << answers[i];
		}
	}
	return 0;
}