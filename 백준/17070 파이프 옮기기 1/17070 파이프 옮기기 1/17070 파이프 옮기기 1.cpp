#include <iostream>
#include <cstring>
using namespace std;

int map[100][100] = { 0, };

int dy[3] = { -1, 0, 1 };
int dx[3] = { -1, 0, 1 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < 2*N; i += 2) {
		for (int j = 0; j < 2*N; j += 2) {
			cin >> map[i][j];
			// 못가는 경우 주위 여백에 전부 -1표시
			if (map[i][j] == 1) {
				for (int k = 0; k < 3; k++) {
					for (int p = 0; p < 3; p++) {
						if (i + dy[k] >= 0 && j + dx[p] >= 0) {
							map[i + dy[k]][j + dx[p]] = -1;
						}
					}
				}
			}
		}
	}

	// 초기화 : 가장 처음에 파이프는 (1, 1)과 (1, 2)를 가리키고 있음 -> (0, 0) (0, 2)에 위치
	map[0][0] = 1;
	map[0][1] = 1;

	for (int i = 0; i < 2*N; i += 2) {
		for (int j = 2; j < 2*N; j += 2) {
			// (0, 2) 채우기
			// 만약 벽이면 continue
			if (map[i][j] == -1) continue;
			else {
				if (i - 1 >= 0 && map[i-1][j] != -1)
					map[i][j] += map[i - 1][j];
				if (j - 1 >= 0 && map[i][j-1] != -1)
					map[i][j] += map[i][j - 1];
				if (i - 1 >= 0 && j - 1 >= 0 && map[i-1][j-1] != -1)
					map[i][j] += map[i - 1][j - 1];
			}

			// (0, 2)에서 (0, 4)로 갈 수 있는가?
			if (map[i][j + 1] != -1) {
				map[i][j + 1] = map[i][j];
				if (i != 0 && map[i-1][j] != -1)
					map[i][j + 1] -= map[i - 1][j];
			}

			// (0, 2)에서 (2, 2)로 갈 수 있는가?
			if (map[i + 1][j] != -1) {
				map[i + 1][j] = map[i][j];
				if (j != 0 && map[i][j - 1] != -1)
					map[i + 1][j] -= map[i][j - 1];
			}

			// (0, 2)에서 (2, 4)로 갈 수 있는가?
			if (map[i+1][j+1] != -1)
				map[i+1][j+1] = map[i][j];
		}
	}

	// 불가능할 경우 0 (예외 처리 조심!)
	if (map[2 * N - 1][2 * N - 1] == -1) cout << 0;
	else cout << map[2 * N - 1][2 * N - 1];
	return 0;
}