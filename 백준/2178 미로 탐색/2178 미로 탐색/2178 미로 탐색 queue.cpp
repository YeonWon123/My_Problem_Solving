// �ð� �ʰ� -> ����Լ� �߽��� DFS(���̿켱Ž��)���δ� �Ұ���
// BFS(�ʺ�켱Ž��)�� ��� �� -> Queue ����ؾ� ��

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
char a[100][100];
int min_value = 9999999;

int recursion(int pos_i, int pos_j, int counts) {
	// �� �������� �� �� �ִٸ� recursion
	if (pos_i == N - 1 && pos_j == M - 1)
		return counts;

	// ���� �� �� �ִ°�?
	if (pos_i - 1 >= 0 && a[pos_i - 1][pos_j] == '1') {
		a[pos_i - 1][pos_j] = '2';	// ���� ���� �� üũ
		min_value = min(min_value, recursion(pos_i - 1, pos_j, counts + 1));
		a[pos_i - 1][pos_j] = '1';	// ���� ���� �� ����
	}

	// �Ʒ��� �� �� �ִ°�?
	if (pos_i + 1 < N && a[pos_i + 1][pos_j] == '1') {
		a[pos_i + 1][pos_j] = '2';	// �Ʒ��� ���� �� üũ
		min_value = min(min_value, recursion(pos_i + 1, pos_j, counts + 1));
		a[pos_i + 1][pos_j] = '1';	// �Ʒ��� ���� �� ����
	}

	// �������� �� �� �ִ°�?
	if (pos_j - 1 >= 0 && a[pos_i][pos_j - 1] == '1') {
		a[pos_i][pos_j - 1] = '2';	// ���� ���� �� üũ
		min_value = min(min_value, recursion(pos_i, pos_j - 1, counts + 1));
		a[pos_i][pos_j - 1] = '1';	// ���� ���� �� ����
	}

	// ���������� �� �� �ִ°�?
	if (pos_j + 1 < M && a[pos_i][pos_j + 1] == '1') {
		a[pos_i][pos_j + 1] = '2';	// ������ ���� �� üũ
		min_value = min(min_value, recursion(pos_i, pos_j + 1, counts + 1));
		a[pos_i][pos_j + 1] = '1';	// ������ ���� �� ����
	}

	// �������� ���� �Ұ���
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
	// (0, 0)���� ����Ͽ� (N-1, M-1)���� �̵��� �� ������ �ϴ� �ּ��� ĭ
	recursion(0, 0, 1);
	cout << min_value;
	return 0;
}