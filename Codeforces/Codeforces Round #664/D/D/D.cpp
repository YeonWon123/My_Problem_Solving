#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[100000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, d, m;
	cin >> n >> d >> m;

	int counts = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > m) {
			counts++;
		}
	}

	sort(a, a + n);
	
	// (counts - 1) * 2���� ���־� �ϴ� ��Ȳ
	for (int i = 0; i < n; i++) {
		
	}
}