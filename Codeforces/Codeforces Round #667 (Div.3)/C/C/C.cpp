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
			// (minus % i)의 나머지가 0인지 + (minus / i) + 1이 n보다 작거나 같은지
			if (minus % i == 0 && minus / i + 1 <= n) break;
		}
		counts = minus / i + 1;
		// 밑으로 내려가면서 출발지점을 찾음
		for (min_value = x - i; min_value > 0 && counts < n; min_value -= i) {
			counts++;
		}
	
		min_value += i;

		// 정답 출력
		for (int j = 0; j < n; j++) {
			cout << min_value << " ";
			min_value += i;
		}
		cout << "\n";
	}

	return 0;
}