// �迭 �������� 1�� ���� ������� �Ѵ�. �׷��� �ڿ������� N-1�� �� ����� �ȴ�.
// �׷��� S / 2 < N�� ���� �Ұ����ϴ� (�迭�� 1�� ������ ���ԵǹǷ�)
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