#define DEBUG

#include <iostream>
#include <queue>
using namespace std;

int N, K;
int ans = 1;
int map[2001][2001];
int index_tree[2001];
int visited[2001][2001];

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << map[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
}


// up_tree
int root_tree(int index) {
	if (index_tree[index] == index) {
		return index;
	}
	else {
		index_tree[index] = root_tree(index_tree[index]);
		return index_tree[index];
	}
}

void union_tree(int index1, int index2) {
	int a = root_tree(index1);
	int b = root_tree(index2);
	if (a == b) return;
	else {
		K--;
		if (root_tree(index1) > root_tree(index2)) {
			index_tree[index1] = index_tree[index2];
		}
		else {
			index_tree[index2] = index_tree[index1];
		}
#ifdef DEBUG
		cout << "출력\n";
		print();
#endif
		if (K == 1) {
			cout << ans << endl;
			exit(0);
		}
	}
}

// 방향을 나타내는 배열을 만들자
int ny[4] = { -1, 0, 1, 0 };
int nx[4] = { 0, -1, 0, 1 };

struct point {
	int x;
	int y;
	int index;
};

queue<point> pos;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			map[i][j] = -1;
			visited[i][j] = 0;
		}
		index_tree[i] = i;
	}

	int x, y;
	point now;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		now.x = x;
		now.y = y;
		now.index = index_tree[i];
		pos.push(now);
		map[x][y] = i;
		visited[x][y] = 1;
#ifdef DEBUG
		print();
#endif
	}
#ifdef DEBUG
	print();
#endif
	point now2;
	while (1) {
		int size = pos.size();
		for (int i = 0; i < size; i++) {
			now = pos.front();
			pos.pop();
			for (int p = 0; p < 4; p++) {
				x = now.x + nx[p];
				y = now.y + ny[p];
				if (x > 0 && x <= N && y > 0 && y <= N) {
					// 내 땅으로 차지하기
					if (map[x][y] == -1) {
						map[x][y] = now.index;
						now2.x = x;
						now2.y = y;
						now2.index = map[x][y];
						pos.push(now2);

						// 인접한 지역에 다른 문명이 있는지 확인
						for (int pp = 0; pp < 4; pp++) {
							int px = x + nx[pp];
							int py = y + ny[pp];
							if (px > 0 && px <= N && py > 0 && py <= N) {
								// 인접한 지역에 문명이 있으면 겹치는지 확인
								if (map[px][py] != -1) {
									union_tree(map[x][y], map[px][py]);
								}
							}
						}
					}
					else {
						// 겹치는 경우 - index_tree를 확인
						// 만약 두 index_tree가 다르면 이를 같게 해 준다.
						union_tree(map[x][y], now.index);
					}
				}	
			}
		}
#ifdef DEBUG
		cout << "출력" << endl;
		print();
#endif
		ans++;
	}

	return 0;
}