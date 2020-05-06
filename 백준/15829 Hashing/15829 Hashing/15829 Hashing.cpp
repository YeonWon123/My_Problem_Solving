#include <iostream>
using namespace std;

long long result[51];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int L; cin >> L;
	string str; cin >> str;

	result[0] = 1;
	for (int i = 1; i < 51; i++) {
		result[i] = result[i - 1] * 31 % 1234567891;
	}

	long long ans = 0;
	long long now = 1;
	long long temp;
	for (int i = 0; i < str.size(); i++) {
		now = 1;
		temp = (int)(str[i] - 'a') + 1;
//		cout << temp << endl;
		now = result[i];
		now *= temp;
		now %= 1234567891;
//		cout << now << endl;
		ans += now;
		ans %= 1234567891; // 여기 빠뜨리지 않기!
	}

	cout << ans;
	return 0;
}