#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

char map[1000][1000];
int visited[1000][1000] = { 0, };
queue<pair<int, int>> BFS;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	char now;
	int a, b;
	int sw = 0;
	for (int i = 0; i < n; i++) {
		a = 0; b = 0;
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (j == 0) {
				now = map[i][j];
				if (map[i][j] == '#') a++;
				else b++;
			}
			else {
				if (map[i][j] != now) {
					now = map[i][j];
					if (map[i][j] == '#') a++;
					else b++;
				}
			}
		}
		if (a != 1) {
			sw = 1;
		}
	}

	if (sw == 0) {
		for (int j = 0; j < m; j++) {
			a = 0; b = 0;
			for (int i = 0; i < n; i++) {
				if (i == 0) {
					now = map[i][j];
					if (map[i][j] == '#') a++;
					else b++;
				}
				else {
					if (map[i][j] != now) {
						now = map[i][j];
						if (map[i][j] == '#') a++;
						else b++;
					}
				}
			}

			if (a != 1) {
				sw = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '#' && visited[i][j] == 0) {
				BFS.push({ i, j });
				visited[i][j] = 1;
				
				while (!BFS.empty()) {

				}
			}
		}
	}

	return 0;
}