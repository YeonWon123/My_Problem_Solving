#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

string big_plus(string a, string b) {
	string ans;
	string bb;
	
	for (int j = 0; j < a.length() - b.length(); j++) {
		bb += "0";
	}
	bb += b;

//	cout << "출력" << endl;
//	cout << a << endl;
//	cout << bb << endl;

	ans.append(a.length() + 1, '0');

	int sum = 0;
	int carry = 0;
	for (int i = 1; i <= a.length(); i++) {
		sum = a[a.length() - i] - '0' + bb[a.length() - i] - '0' + carry;
		carry = sum / 10;
		sum %= 10;
//		cout << "계산 결과 " << sum << " " << carry << endl;
		ans[a.length() + 1 - i] = sum + '0';
	}
	ans[0] = carry + 48;

	return ans;
}

string big_minus(string a, string b) {
	string ans;
	string bb;

	for (int j = 0; j < a.length() - b.length(); j++) {
		bb += "0";
	}
	bb += b;

//	cout << "출력" << endl;
//	cout << a << endl;
//	cout << bb << endl;

	ans.append(a.length(), '0');

	int sum = 0;
	for (int i = 1; i <= a.length(); i++) {
		sum = (a[a.length() - i] - '0') - (bb[a.length() - i] - '0');
//		cout << sum << endl;
		if (sum < 0) {
			a[a.length() - i - 1] -= 1;
			sum += 10;
		}
//		cout << "계산 결과 " << sum << endl;
		ans[a.length() - i] = sum + '0';
	}

	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, s, counts, i, target;
	string n, n_str;

	cin >> T;
	while (T--) {
		n_str = "";
		counts = 0; target = 0;
		cin >> n >> s;
		
		int i; int sw = 0;
		for (i = 0; i < n.length(); i++) {
			counts += n[i] - 48;
			if (counts > s) {
				sw = 1;
				counts -= n[i] - 48;
				break;
			}
			else if (counts < s) {
				n_str += n[i];
			}
		}

		if (sw == 0) {
			cout << 0 << "\n";
			continue;
		}

		if (n_str == "") {
			n_str += "1";
			// 0을 n_length만큼 채워야 함
			for (int p = 0; p < n.length(); p++) {
				n_str += "0";
			}

			// 그리고 n_str에서 n을 빼면 됨
			// 그 결과를 long long으로 바꿔서 출력함
//			cout << "0출력" << endl;
//			cout << n_str << endl;
			string str = big_minus(n_str, n);
			int sw2 = 0;
			for (int i = 0; i < str.size(); i++) {
				if ((str[i] != '0' && sw2 == 0) || sw2 == 1) {
					cout << str[i];
					sw2 = 1;
				}
			}
			cout << endl;
		}
		else {
			// n_str의 남은 부분을 전부 0으로 만들자
			string n_str2 = "1";
			int p = n_str.length();
			for (i = p; i < n.length(); i++) {
				n_str += "0";
				n_str2 += "0";
			}

			// n_str + n_str2 - n
//			cout << "else출력" << endl;
//			cout << n_str << " " << n_str2 << endl;
//			cout << big_plus(n_str, n_str2) << endl;
			string str = big_minus(big_plus(n_str, n_str2), n);
			int sw2 = 0;
			for (int i = 0; i < str.size(); i++) {
				if ((str[i] != '0' && sw2 == 0) || sw2 == 1) {
					cout << str[i];
					sw2 = 1;
				}
			}
			cout << endl;
		}

	}

	return 0;
}