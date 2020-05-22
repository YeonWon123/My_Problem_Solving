// n-Queens Problem

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int col[20], N, ans = 0;

bool promising(int k) {
	// col[1] = 4�� ��� 1�� 4��
	// col[4] = 8�� ��� 4�� 8��
	// i == k �̸� false
	// ����, ����, �밢��
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
		// 1�࿡�� Queen�� i���� �ΰ� Backtracking�Ѵ�.
		memset(col, 0, sizeof(col));
		col[1] = i; // 1�࿡ ���� Queen�� �ڸ��� ���Ѵ�.
		queen(1);   // �װ� ������� DFS(!)�� �Ѵ�.
	}
	cout << ans;
}