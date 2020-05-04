// 시간 초과 -> 재귀함수 중심의 DFS(깊이우선탐색)으로는 불가능
// BFS(너비우선탐색)을 써야 함 -> Queue 사용해야 함

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
char a[100][100];
int min_value = 9999999;

int recursion(int pos_i, int pos_j, int counts) {
	// 네 방향으로 갈 수 있다면 recursion
	if (pos_i == N - 1 && pos_j == M - 1)
		return counts;

	// 위로 갈 수 있는가?
	if (pos_i - 1 >= 0 && a[pos_i - 1][pos_j] == '1') {
		a[pos_i - 1][pos_j] = '2';	// 위로 가는 거 체크
		min_value = min(min_value, recursion(pos_i - 1, pos_j, counts + 1));
		a[pos_i - 1][pos_j] = '1';	// 위로 가는 거 해제
	}

	// 아래로 갈 수 있는가?
	if (pos_i + 1 < N && a[pos_i + 1][pos_j] == '1') {
		a[pos_i + 1][pos_j] = '2';	// 아래로 가는 거 체크
		min_value = min(min_value, recursion(pos_i + 1, pos_j, counts + 1));
		a[pos_i + 1][pos_j] = '1';	// 아래로 가는 거 해제
	}

	// 왼쪽으로 갈 수 있는가?
	if (pos_j - 1 >= 0 && a[pos_i][pos_j - 1] == '1') {
		a[pos_i][pos_j - 1] = '2';	// 왼쪽 가는 거 체크
		min_value = min(min_value, recursion(pos_i, pos_j - 1, counts + 1));
		a[pos_i][pos_j - 1] = '1';	// 왼쪽 가는 거 해제
	}

	// 오른쪽으로 갈 수 있는가?
	if (pos_j + 1 < M && a[pos_i][pos_j + 1] == '1') {
		a[pos_i][pos_j + 1] = '2';	// 오른쪽 가는 거 체크
		min_value = min(min_value, recursion(pos_i, pos_j + 1, counts + 1));
		a[pos_i][pos_j + 1] = '1';	// 오른쪽 가는 거 해제
	}

	// 종점까지 도달 불가능
	return 99999999;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
		}
	}
	a[0][0] = '2';
	// (0, 0)에서 출발하여 (N-1, M-1)으로 이동할 때 지나야 하는 최소의 칸
	recursion(0, 0, 1);
	cout << min_value;
	return 0;
}