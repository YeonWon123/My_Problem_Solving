// Priority Queue�� �̿��ؼ� Dijkstra Ǯ��

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// ������ ����
int V;

const int MAX_V = 1003;
const int INF = 999999999;

// �׷����� ���� ����Ʈ. (����� ���� ��ȣ, ���� ����ġ) ���� ��´�.
vector<pair<int, int> > adj[MAX_V];
vector<int> dijkstra(int src) {
	// dist��� ���͸� �����ϴµ�, V�� ũ���, INF�� �ʱ�ȭ�ؼ�
	// ���� ũ�Ⱑ 4�ε�, dist[4]�� �Ұ�������
	vector<int> dist(V+1, INF); 
	
	dist[src] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));

	// Queue�� �� �� ������ ��� Ž��
	while (!pq.empty()) {
		int cost = -pq.top().first; // �Ÿ��� ��ȣ�� �ٲ�
		int here = pq.top().second;
		pq.pop();
		
		// �ּҰŸ��� ���ϹǷ�, �ּҰŸ��� �ƴϸ� �� �ʿ䰡 ����.
		if (dist[here] < cost) continue;

		// �ּҰŸ����, �̿��� ������ ��� Ȯ���� ����
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
		
			// �� ª�� ��θ� �߰��ϸ�,
			// dist[]�� �����ϰ� �켱���� ť�� �ִ´�.
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				// �Ÿ��� ��ȣ�� �ٲپ, �Ÿ��� ���� �������� ���������� �Ѵ�.
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; // ��ǻ�͵��� ��ȣ�� 1���� N������ ����
	cin >> N >> M;
	V = N;

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;

		adj[A].push_back(make_pair(B, C));
		adj[B].push_back(make_pair(A, C));
	}

	vector<int> result = dijkstra(1);
	
	// cout << N - 1 << "\n";
	// for (int i = 2; i < V; i++) {
		vector<int> result2 = dijkstra(1);
		for (int i = 0; i <= result2.size(); i++) {
			cout << i << " " << result[i] << "\n";
		}
		/*
		int min_value = INF;
		int pos = 0;
		for (int j = 0; j <= result2.size(); j++) {
			if (min_value > result2[j]) {
				min_value = result2[j];
				pos = j;
			}
		}
		cout << i << " " << pos << "\n";
		*/
	 // }
}