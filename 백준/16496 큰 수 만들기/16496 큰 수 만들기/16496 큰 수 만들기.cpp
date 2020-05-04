#include <iostream>
#include <algorithm>
using namespace std;

string a[1000];

bool compare(string a, string b) {
	return a + b > b + a;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	
	int zero = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i]; // string은 공백을 구분함
		if (a[i] != "0") zero = 1;
	}

	if (zero == 0) {
		cout << 0;
		return 0;
	}

	sort(a, a + N, compare);

	for (int j = 0; j < N; j++) {
		cout << a[j];
	}
}