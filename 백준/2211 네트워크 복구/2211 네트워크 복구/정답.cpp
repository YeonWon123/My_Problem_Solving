// Priority Queue�� �̿��� Dijkstra Ǯ�� - O((V + E)logN)

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
	vector<struct line> distance(vertex); // ���������� �������� �Ÿ�(dist)�� ��Ÿ���� vector
	distance[start].weight = 0;

	priority_queue<pair<int, int>> pq; // first: ���(cost), Second: ����(vertex)
	pq.push(make_pair(0, start)); // �ʱ� ���, ��������

	// queue�� �� �� ������ ��� Ž��
	while (!pq.empty()) {
		int cost = -pq.top().first; // �Ÿ��� ��ȣ�� �ٲ�
		int curVertex = pq.top().second;
		pq.pop();

		// �ּҰŸ��� ���ϱ� ������, �ּҰŸ��� �ƴϸ� �� �ʿ䰡 ����
		if (distance[curVertex].weight < cost) {
			continue;
		}

		// �ּҰŸ����, �̿��� ������ ��� Ȯ���� ����
		for (int i = 0; i < graph[curVertex].size(); i++) {
			int neighbor = graph[curVertex][i].first;
			int neighborDistance = cost + graph[curVertex][i].second;

			// �ּ� ��θ� �߰��ϸ� ������ �ش�.
			if (distance[neighbor].weight > neighborDistance) {
				distance[neighbor].weight = neighborDistance;
				distance[neighbor].min_vertex = curVertex;
				// �Ÿ��� ��ȣ�� �ٲپ�, �Ÿ��� ���� �������� ���������� ��
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

	int N, M;	// ��ǻ�͵��� ��ȣ�� 1���� N������ ����
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