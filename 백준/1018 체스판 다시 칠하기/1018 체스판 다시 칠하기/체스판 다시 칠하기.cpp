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

	// 다 해보자
	int ans = 999;
	int sw = 1;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int temp = 0;
			// 탐색을 해 보면, 색칠해야 되는 사각형과 색칠하지 않아도 되는 사각형이 나오게 된다.
			// 색칠해야 되는 사각형이 더 많으면, 색칠하지 않아도 되는 사각형을 색칠하는 식으로 반대로 한다.
			// 맨 왼쪽 위 칸을 흰색(W)으로 칠해야 한다고 가정하고 하자.
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