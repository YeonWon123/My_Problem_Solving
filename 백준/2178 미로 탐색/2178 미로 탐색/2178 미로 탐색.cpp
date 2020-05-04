// 시간 초과 -> 재귀함수 중심의 DFS(깊이우선탐색)으로는 불가능
// BFS(너비우선탐색)을 써야 함 -> Queue 사용해야 함

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

	// (0, 0)에서 출발하여 (N-1, M-1)으로 이동할 때 지나야 하는 최소의 칸
	// 내 자신에서 갈 수 있는 좌표가 있으면 그 좌표를 Queue에 넣는다.
	p.push({ 0, 0, 1 });

	while (!p.empty()) {
		point q = p.front();	// 큐에서 맨 위에 있는 걸 꺼낸다.
		p.pop();				// 큐의 맨 위에 있는 걸 빼낸다.
		// 네 방향으로 살펴서 들어갈 수 있으면 queue에 넣음
		for (int i = 0; i < 4; i++) {
			// 경계 조건 확인, 벽이나 이미 탐사했던 지역이 아닌지 확인
			if (q.i + d_i[i] >= 0 && q.i + d_i[i] < N && q.j + d_j[i] >= 0 && q.j + d_j[i] < M && a[q.i+d_i[i]][q.j+d_j[i]] == '1') { 

				// 만약 목적지라면 횟수 출력 후 종료하면 됨
				if (q.i + d_i[i] == N-1 && q.j + d_j[i] == M-1) {
					cout << q.depth + 1;
					return 0;
				}

				a[q.i + d_i[i]][q.j + d_j[i]] = '2';					// 그 지역은 탐방했음
				p.push({ q.i + d_i[i], q.j + d_j[i], q.depth + 1 });	// 큐에 넣고 나중에 그 지역을 중심으로 또 네 방향을 살펴볼 예정
			}
		}
	}

	return 0;
}