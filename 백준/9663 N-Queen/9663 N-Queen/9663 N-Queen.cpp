// n-Queens Problem

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int col[20], N, ans = 0;

bool promising(int k) {
	// col[1] = 4일 경우 1행 4열
	// col[4] = 8일 경우 4행 8열
	// i == k 이면 false
	// 가로, 세로, 대각선
	for (int i = 1; i < k; i++) {
		if (col[i] == col[k] || abs(col[i] - col[k]) == abs(i - k)) {
			return false;
		}
	}

	return true;
}

void queen(int i) {
	int j;
	if (i == N) ans++;
	else {
		for (j = 1; j <= N; j++) {
			col[i + 1] = j;
			if (promising(i + 1))
				queen(i + 1);
			else
				col[i + 1] = 0;
		}
	}
	col[i] = 0;
}

int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		// 1행에는 Queen을 i열에 두고 Backtracking한다.
		memset(col, 0, sizeof(col));
		col[1] = i; // 1행에 놓은 Queen의 자리를 정한다.
		queen(1);   // 그걸 기반으로 DFS(!)를 한다.
	}
	cout << ans;
}