#include <iostream>
#include <algorithm>
using namespace std;

// roll[i][j][k] : ù��° �ֻ��� ���� i, �ι�° �ֻ��� ���� j, ����° �ֻ��� ���� k�϶� ��� ���
int roll[6][6][6];
int n_sum = 0; // roll[i][j][k]�� �� ��

// DP[i] : i��°�� �ֻ����� ������ ��, ���� �� �ִ� ��� ����� ��
// DP[i] = DP[i-1] + n_sum*6^(i-3)
// ans = DP[i] * 1/(6*6*6 + 6*6*6*6 + 6*6*6*6*6 + ...)�� �ϸ� �ȴ�.
// �ֳĸ�, N�� 5��� �ϸ�, �ֻ����� 3��, 4��, 5�� ������ ���� ��� �����ϱ� �����̴�.

int main(void)
{
	int N;
	cin >> N;

	// roll �迭 �ʱ�ȭ
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 6; k++) {
				// ���� ���� 3�� ������ ���
				if (i == j && j == k) {
					roll[i][j][k] = 10000 + i * 1000;
				}
				// ���� ���� 2�� ������ ���
				else if (i == j || j == k || k == i) {
					int temp;
					if (i == j) temp = i;
					else if (j == k) temp = j;
					else temp = k;
					roll[i][j][k] = 1000 + temp * 100;
				}
				// ��� �ٸ� ���� ���
				else {
					int temp = max(i, max(j, k));
					roll[i][j][k] = temp * 100;
				}
			}
		}
	}

	// for���� ���鼭 DP �迭�� ä���� ��


}