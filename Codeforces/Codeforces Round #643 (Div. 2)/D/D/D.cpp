// 배열 조합으로 1을 절대 못만들게 한다. 그러면 자연스럽게 N-1도 못 만들게 된다.
// 그래서 S / 2 < N인 경우는 불가능하다 (배열에 1이 무조건 포함되므로)
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, S;
	cin >> N >> S;
	
	if (N == 1 && S != 1) {
		cout << "YES\n" << S << "\n" << 1 << "\n";
		return 0;
	}
	
	if (S / 2 < N) {
		cout << "NO";
	}
	else {
		cout << "YES\n";
		for (int i = 0; i < N-1; i++) {
			cout << S / N << " ";
		}
		cout << S - (S / N * (N - 1)) << "\n";

		cout << 1;
	}

	return 0;
}