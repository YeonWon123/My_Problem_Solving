// �ð� �ʰ� -> ����Լ� �߽��� DFS(���̿켱Ž��)���δ� �Ұ���
// BFS(�ʺ�켱Ž��)�� ��� �� -> Queue ����ؾ� ��

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
char a[100][100];

typedef struct POINT {
	int i;
	int j;
	int depth;
} point;

queue<point> p;

int min_value;

int d_i[4] = { -1, 1, 0, 0 };
int d_j[4] = { 0, 0, -1, 1 };

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

	// (0, 0)���� ����Ͽ� (N-1, M-1)���� �̵��� �� ������ �ϴ� �ּ��� ĭ
	// �� �ڽſ��� �� �� �ִ� ��ǥ�� ������ �� ��ǥ�� Queue�� �ִ´�.
	p.push({ 0, 0, 1 });

	while (!p.empty()) {
		point q = p.front();	// ť���� �� ���� �ִ� �� ������.
		p.pop();				// ť�� �� ���� �ִ� �� ������.
		// �� �������� ���켭 �� �� ������ queue�� ����
		for (int i = 0; i < 4; i++) {
			// ��� ���� Ȯ��, ���̳� �̹� Ž���ߴ� ������ �ƴ��� Ȯ��
			if (q.i + d_i[i] >= 0 && q.i + d_i[i] < N && q.j + d_j[i] >= 0 && q.j + d_j[i] < M && a[q.i+d_i[i]][q.j+d_j[i]] == '1') { 

				// ���� ��������� Ƚ�� ��� �� �����ϸ� ��
				if (q.i + d_i[i] == N-1 && q.j + d_j[i] == M-1) {
					cout << q.depth + 1;
					return 0;
				}

				a[q.i + d_i[i]][q.j + d_j[i]] = '2';					// �� ������ Ž������
				p.push({ q.i + d_i[i], q.j + d_j[i], q.depth + 1 });	// ť�� �ְ� ���߿� �� ������ �߽����� �� �� ������ ���캼 ����
			}
		}
	}

	return 0;
}