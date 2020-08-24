//#define DEBUG

#include <iostream>
#include <queue>
using namespace std;

int R, C;
char map[1500][1500];
char visited1[1500][1500];
char visited2[1500][1500];

// 정답
int ans = 0;

// 방향을 나타내보자
int ny[4] = { -1, 0, 1, 0 };
int nx[4] = { 0, -1, 0, 1 };

// 한 백조의 위치는 고정시켜놓음
pair<int, int> target1;
pair<int, int> target2;

// 다음 턴에 백조가 갈 수 있는 영역을 queue에 보관하고 갱신
queue<pair<int, int>> swan;

// 다음 번에 녹는 영역을 queue에 보관하고 갱신
queue<pair<int, int>> water;


void print2() {
	cout << "\n출력\n\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << visited1[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;

	cout << "\n출력\n\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << visited2[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
}


void print() {
	cout << "\n출력\n\n";
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
		// 테두리에서 벗어나지 않는지 살펴봄
		if (y + ny[p] >= 0 && y + ny[p] < R && x + nx[p] >= 0 && x + nx[p] < C && visited1[y+ ny[p]][x+nx[p]] == '0') {
			visited1[y + ny[p]][x + nx[p]] = '1';
			// 주위 네 방향 중 . 혹은 'L'가 있다면 ('X'가 아니라면)
			// water 큐에 넣자
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

			// 내 위치에 백조가 있으면
			if (map[i][j] == 'L') {
				// 첫번째 백조는 target1에 넣고
				if (sw == 0) {
					sw++;
					target1.first = i; target1.second = j;
				}
				// 두번째 백조는 swan 큐에 넣음
				else {
					target2.first = i; target2.second = j;
				}
			}
		}
	}

	// 백조들이 갈 수 있는 공간을 전부 탐색해 보자
	// 하나는 고정시켜 놓고, 다른 하나를 기준으로 탐색해 보자
	// target2를 움직여서 target1에 도달할 수 있을까?
	move1(target2.first, target2.second);
#ifdef DEBUG
	print2();
#endif
	// 초기설정
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			// 내가 지금 X인데 주위 네 방향 중 .가 있다면
			// 다음에 내가 녹을 차례
			if (map[i][j] == 'X') {
				for (int p = 0; p < 4; p++) {
					// 테두리에서 벗어나지 않는지 살펴봄
					if (i + ny[p] >= 0 && i + ny[p] < R && j + nx[p] >= 0 && j + nx[p] < C && visited2[i][j] == '0') {
						// 주위 네 방향 중 . 혹은 'L'가 있다면 ('X'가 아니라면)
						// water 큐에 넣자
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
			// 테두리에서 벗어나지 않는지 살펴봄
			if (now.first + ny[p] >= 0 && now.first + ny[p] < R && now.second + nx[p] >= 0 && now.second + nx[p] < C && visited2[now.first + ny[p]][now.second + nx[p]] == '0') {
				// 주위 네 방향 중 'X'가 있다면
				// water 큐에 넣자
				if (map[now.first + ny[p]][now.second + nx[p]] == 'X') {
					water.push({ now.first + ny[p], now.second + nx[p] });
					visited2[now.first + ny[p]][now.second + nx[p]] = '1';
				}
			}
		}
	}
#ifdef DEBUG
	cout << "처음끝" << endl;
	print();

	print2();
#endif
	ans++;

	while (1) {
		// 백조 이동
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
				// 테두리에서 벗어나지 않는지 살펴봄
				if (now.first + ny[p] >= 0 && now.first + ny[p] < R && now.second + nx[p] >= 0 && now.second + nx[p] < C && visited2[now.first + ny[p]][now.second + nx[p]] == '0') {
					// 주위 네 방향 중 'X'가 있다면
					// water 큐에 넣자
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