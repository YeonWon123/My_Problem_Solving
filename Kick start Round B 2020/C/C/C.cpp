#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

stack<int> input;
string str;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, pp;
	cin >> T;
	long long x_pos, y_pos;
	long long move_count = 0;
	for (int i = 0; i < T; i++) {
		str = "";
		move_count = 1;
		x_pos = 0;
		y_pos = 0;
		
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '2' || str[j] == '3' || str[j] == '4' || str[j] == '5' || str[j] == '6' || str[j] == '7' || str[j] == '8' || str[j] == '9') {
				pp = (int)(str[j] - '0');
				input.push(pp);
				move_count = move_count * pp;
			}
			else if (str[j] == ')') {
				pp = input.top();
				input.pop();
				move_count = move_count / pp;
			}
			else if (str[j] == '(') {
				continue;
			}
			else if (str[j] == 'N') {
				y_pos -= move_count;
			}
			else if (str[j] == 'S') {
				y_pos += move_count;
			}
			else if (str[j] == 'E') {
				x_pos += move_count;
			}
			else if (str[j] == 'W') {
				x_pos -= move_count;
			}

			if (x_pos >= 1000000000 || x_pos < -1000000000) {
				x_pos %= 1000000000;
			}

			if (y_pos >= 1000000000 || y_pos < -1000000000) {
				y_pos %= 1000000000;
			}
		}

		if (x_pos < 0) {
			x_pos += 1000000000;
		}
		if (y_pos < 0) {
			y_pos += 1000000000;
		}

		cout << "Case #" << i + 1 << ": " << x_pos+1 << " " << y_pos+1 << "\n";
	}

	return 0;
}