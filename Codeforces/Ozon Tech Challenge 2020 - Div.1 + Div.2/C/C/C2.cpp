// 비둘기집의 원리를 이용하여 문제풀기

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int a[200000];
int b[1000];
unsigned long long answer = 1;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	if (n > m) {
		cout << 0;
		return 0;
	}

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 1; j <= i; j++) {
			temp = abs(a[i] - a[i - j]) % m;
			answer = temp * answer;
			answer = answer % m;
		}
	}
	   
	cout << answer % m;
	return 0;
}