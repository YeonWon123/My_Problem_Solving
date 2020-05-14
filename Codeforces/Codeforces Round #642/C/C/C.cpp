#include <iostream>
#include <algorithm>
using namespace std;

int a[30];
int b[30];

long long ans[500001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ans[0] = 0;
	long long p = 1;
	// cout << ans[0] << "\n";
	for (int i = 1; i < 250100; i++) {
		ans[i] = ans[i - 1] + (long long)i * 8 * i;
	//	cout << ans[i] << "\n";
	}

	int t; cin >> t;
	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << ans[n / 2] << "\n";
	}

	return 0;
}