//#define DEBUG

#include <iostream>
#include <queue>
using namespace std;

int R, C;
char map[1500][1500];
char visited1[1500][1500];
char visited2[1500][1500];

// ����
int ans = 0;

// ������ ��Ÿ������
int ny[4] = { -1, 0, 1, 0 };
int nx[4] = { 0, -1, 0, 1 };

// �� ������ ��ġ�� �������ѳ���
pair<int, int> target1;
pair<int, int> target2;

// ���� �Ͽ� ������ �� �� �ִ� ������ queue�� �����ϰ� ����
queue<pair<int, int>> swan;

// ���� ���� ��� ������ queue�� �����ϰ� ����
queue<pair<int, int>> water;


void print2() {
	cout << "\n���\n\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << visited1[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;

	cout << "\n���\n\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << visited2[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
}


void print() {
	cout << "\n���\n\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
}

void move1(int y, int x) {
	for (int p = 0; p < 4; p++) {
		// �׵θ����� ����� �ʴ��� ���캽
		if (y + ny[p] >= 0 && y + ny[p] < R && x + nx[p] >= 0 && x + nx[p] < C && visited1[y+ ny[p]][x+nx[p]] == '0') {
			visited1[y + ny[p]][x + nx[p]] = '1';
			// ���� �� ���� �� . Ȥ�� 'L'�� �ִٸ� ('X'�� �ƴ϶��)
			// water ť�� ����
			if (map[y + ny[p]][x + nx[p]] == 'X') {
				swan.push({ y + ny[p], x + nx[p] });
			}
			else if (map[y + ny[p]][x + nx[p]] == '.') {
				move1(y + ny[p], x + nx[p]);
			}
			else if (y + ny[p] == target1.first && x + nx[p] == target1.second) {
				cout << ans << "\n";
				exit(0);
			}
		}
	}
}

int main(void)
{
	int sw = 0;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			visited1[i][j] = '0';
			visited2[i][j] = '0';

			cin >> map[i][j];

			// �� ��ġ�� ������ ������
			if (map[i][j] == 'L') {
				// ù��° ������ target1�� �ְ�
				if (sw == 0) {
					sw++;
					target1.first = i; target1.second = j;
				}
				// �ι�° ������ swan ť�� ����
				else {
					target2.first = i; target2.second = j;
				}
			}
		}
	}

	// �������� �� �� �ִ� ������ ���� Ž���� ����
	// �ϳ��� �������� ����, �ٸ� �ϳ��� �������� Ž���� ����
	// target2�� �������� target1�� ������ �� ������?
	move1(target2.first, target2.second);
#ifdef DEBUG
	print2();
#endif
	// �ʱ⼳��
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			// ���� ���� X�ε� ���� �� ���� �� .�� �ִٸ�
			// ������ ���� ���� ����
			if (map[i][j] == 'X') {
				for (int p = 0; p < 4; p++) {
					// �׵θ����� ����� �ʴ��� ���캽
					if (i + ny[p] >= 0 && i + ny[p] < R && j + nx[p] >= 0 && j + nx[p] < C && visited2[i][j] == '0') {
						// ���� �� ���� �� . Ȥ�� 'L'�� �ִٸ� ('X'�� �ƴ϶��)
						// water ť�� ����
						if (map[i + ny[p]][j + nx[p]] != 'X') {
							water.push({ i, j });
							visited2[i][j] = '1';
							break;
						}
					}
				}
			}
		}
	}

	int sizes = water.size();
	pair<int, int> now;
	for (int i = 0; i < sizes; i++) {
		now = water.front();
		water.pop();
#ifdef DEBUG
		cout << now.first << " " << now.second << endl;
#endif
		map[now.first][now.second] = '.';
		for (int p = 0; p < 4; p++) {
			// �׵θ����� ����� �ʴ��� ���캽
			if (now.first + ny[p] >= 0 && now.first + ny[p] < R && now.second + nx[p] >= 0 && now.second + nx[p] < C && visited2[now.first + ny[p]][now.second + nx[p]] == '0') {
				// ���� �� ���� �� 'X'�� �ִٸ�
				// water ť�� ����
				if (map[now.first + ny[p]][now.second + nx[p]] == 'X') {
					water.push({ now.first + ny[p], now.second + nx[p] });
					visited2[now.first + ny[p]][now.second + nx[p]] = '1';
				}
			}
		}
	}
#ifdef DEBUG
	cout << "ó����" << endl;
	print();

	print2();
#endif
	ans++;

	while (1) {
		// ���� �̵�
		int size = swan.size();
		for (int i = 0; i < size; i++) {
			now = swan.front();
			swan.pop();
			move1(now.first, now.second);
		}

		int sizes = water.size();
		for (int i = 0; i < sizes; i++) {
			now = water.front();
			water.pop();
			map[now.first][now.second] = '.';
			for (int p = 0; p < 4; p++) {
				// �׵θ����� ����� �ʴ��� ���캽
				if (now.first + ny[p] >= 0 && now.first + ny[p] < R && now.second + nx[p] >= 0 && now.second + nx[p] < C && visited2[now.first + ny[p]][now.second + nx[p]] == '0') {
					// ���� �� ���� �� 'X'�� �ִٸ�
					// water ť�� ����
					if (map[now.first + ny[p]][now.second + nx[p]] == 'X') {
						water.push({ now.first + ny[p], now.second + nx[p] });
						visited2[now.first + ny[p]][now.second + nx[p]] = '1';
					}
				}
			}
		}

		ans++;
#ifdef DEBUG
		print();
#endif

	}

	return 0;
}