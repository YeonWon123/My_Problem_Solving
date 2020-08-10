// Priority Queue를 이용해서 Dijkstra 풀기

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 정점의 개수
int V;

const int MAX_V = 1003;
const int INF = 999999999;

// 그래프의 인접 리스트. (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, int> > adj[MAX_V];
vector<int> dijkstra(int src) {
	// dist라는 벡터를 선언하는데, V의 크기로, INF로 초기화해서
	// 벡터 크기가 4인데, dist[4]는 불가능하지
	vector<int> dist(V+1, INF); 
	
	dist[src] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));

	// Queue가 다 빌 때까지 계속 탐색
	while (!pq.empty()) {
		int cost = -pq.top().first; // 거리의 부호를 바꿈
		int here = pq.top().second;
		pq.pop();
		
		// 최소거리를 원하므로, 최소거리가 아니면 할 필요가 없다.
		if (dist[here] < cost) continue;

		// 최소거리라면, 이웃한 지점을 모두 확인해 보자
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
		
			// 더 짧은 경로를 발견하면,
			// dist[]를 갱신하고 우선순위 큐에 넣는다.
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				// 거리의 부호를 바꾸어서, 거리가 작은 정점부터 꺼내지도록 한다.
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

	int N, M; // 컴퓨터들의 번호는 1부터 N까지의 정수
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