#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, n, x, y, i, minus, counts, min_value, max_value;
	cin >> T;
	while (T--) {
		cin >> n >> x >> y;
		minus = y - x;
		counts = 0;
		
		for (i = 1; i <= minus; i++) {
			// (minus % i)�� �������� 0���� + (minus / i) + 1�� n���� �۰ų� ������
			if (minus % i == 0 && minus / i + 1 <= n) break;
		}
		counts = minus / i + 1;
		// ������ �������鼭 ��������� ã��
		for (min_value = x - i; min_value > 0 && counts < n; min_value -= i) {
			counts++;
		}
	
		min_value += i;

		// ���� ���
		for (int j = 0; j < n; j++) {
			cout << min_value << " ";
			min_value += i;
		}
		cout << "\n";
	}

	return 0;
}