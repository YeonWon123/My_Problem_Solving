// answer로 long long을 써야 함에 주의!

#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	long long temp;
	for (int i = 0; i < m; i++) {
		temp = arr[0] + arr[1];
		arr[0] = temp;
		arr[1] = temp;
		sort(arr, arr + n);
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += arr[i];
	}

	cout << ans;
	return 0;
}