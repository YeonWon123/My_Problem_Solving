// bfs 사용

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[1000];
int visited[1000] = { 0 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// 0번 정점부터 n-1번 정점까지 bfs로 탐색
	int ans = 0, sw = 0;
	for (int i = 0; i < N; i++) {
		sw = 0;
		queue<int> bfs_queue;
		bfs_queue.push(i);

		int temp;
		while (!bfs_queue.empty()) {
			temp = bfs_queue.front();
			bfs_queue.pop();

			if (visited[temp] == 0) {
				visited[temp] = 1;
				if (sw == 0) {
					sw = 1; ans++;
				}
			}
			else {
				continue;
			}

			for (int j = 0; j < graph[temp].size(); j++) {
				bfs_queue.push(graph[temp][j]);
			}
		}
	}

	cout << ans;
	return 0;
}