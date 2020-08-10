// Priority Queue를 이용해 Dijkstra 풀기 - O((V + E)logN)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 1001;
const int INF = 999999;

int N, M;
vector<pair<int, int>> graph[MAX];
struct line {
	int min_vertex;
	int weight;
	line() {
		min_vertex = -1;
		weight = INF;
	}
};

vector<struct line> dijkstra(int start, int vertex) {
	vector<struct line> distance(vertex); // 시작지점을 기준으로 거리(dist)를 나타내는 vector
	distance[start].weight = 0;

	priority_queue<pair<int, int>> pq; // first: 비용(cost), Second: 정점(vertex)
	pq.push(make_pair(0, start)); // 초기 비용, 시작지점

	// queue가 다 빌 때까지 계속 탐색
	while (!pq.empty()) {
		int cost = -pq.top().first; // 거리의 부호를 바꿈
		int curVertex = pq.top().second;
		pq.pop();

		// 최소거리를 원하기 때문에, 최소거리가 아니면 할 필요가 없음
		if (distance[curVertex].weight < cost) {
			continue;
		}

		// 최소거리라면, 이웃한 지점을 모두 확인해 보자
		for (int i = 0; i < graph[curVertex].size(); i++) {
			int neighbor = graph[curVertex][i].first;
			int neighborDistance = cost + graph[curVertex][i].second;

			// 최소 경로를 발견하면 갱신해 준다.
			if (distance[neighbor].weight > neighborDistance) {
				distance[neighbor].weight = neighborDistance;
				distance[neighbor].min_vertex = curVertex;
				// 거리의 부호를 바꾸어, 거리가 작은 정점부터 꺼내지도록 함
				pq.push(make_pair(-neighborDistance, neighbor));
			}
		}
	}

	return distance;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;	// 컴퓨터들의 번호는 1부터 N까지의 정수
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;

		graph[A].push_back(make_pair(B, C));
		graph[B].push_back(make_pair(A, C));
	}

	vector<struct line> result = dijkstra(1, N + 1);

	int counts = 0;
	for (int i = 1; i <= N; i++) {
		if (result[i].min_vertex != -1)
			counts++;
	}

	cout << counts << "\n";
	for (int i = 1; i <= N; i++) {
		if (result[i].min_vertex != -1)
			cout << i << " " << result[i].min_vertex << "\n";
	}

	return 0;
}