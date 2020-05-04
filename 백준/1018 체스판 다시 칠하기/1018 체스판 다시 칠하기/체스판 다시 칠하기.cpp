#include <iostream>
#include <algorithm>
using namespace std;

char board[50][50];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	// �� �غ���
	int ans = 999;
	int sw = 1;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int temp = 0;
			// Ž���� �� ����, ��ĥ�ؾ� �Ǵ� �簢���� ��ĥ���� �ʾƵ� �Ǵ� �簢���� ������ �ȴ�.
			// ��ĥ�ؾ� �Ǵ� �簢���� �� ������, ��ĥ���� �ʾƵ� �Ǵ� �簢���� ��ĥ�ϴ� ������ �ݴ�� �Ѵ�.
			// �� ���� �� ĭ�� ���(W)���� ĥ�ؾ� �Ѵٰ� �����ϰ� ����.
			for (int k = i; k < i + 8; k++) {
				for (int r = j; r < j + 8; r++) {
					if (sw == 1 && board[k][r] != 'W') temp++;
					else if (sw == -1 && board[k][r] != 'B') temp++;

					sw *= -1;
				}
				sw *= -1;
			}
			if (64 - temp < temp) temp = 64 - temp;
			ans = min(ans, temp);
		}
	}
	cout << ans;
	return 0;
}