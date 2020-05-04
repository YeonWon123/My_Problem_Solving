#include <iostream>
using namespace std;

#define INF 999999999
#define SIZE 6000			// maximum size is M*2 + W + 1 = 5201

typedef struct {
	int u, v, w;			// start point, end point, weight
} Edge;

int NODES, EDGES, WORMS;	// the number of nodes and edges and wormholes 
Edge edges[SIZE];			// input graph edges
int dist[SIZE];				// dist[i]: the minimum distance from source s to node i

// 음의 가중치가 있을 경우 -1 리턴, 정상종료시 0 리턴
int BellmanFord() {
	int i, j;

	// Step 1. Initialize graph (초기화)
	for (i = 0; i < NODES; i++) {
		// at the beginning, all vertices have weight of infinity
		dist[i] = INF;
	}

	// Step 2. Relax edges repeatedly: O(|V||E|)
	for (i = 0; i < NODES - 1; i++) {
		for (j = 0; j < EDGES + WORMS; j++) {
			if (dist[edges[j].v] > dist[edges[j].u] + edges[j].w) {
				dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
			}
		}
	}

	// Step 3. Check for negative-weight cycles
	for (j = 0; j < EDGES + WORMS; j++) {
		if (dist[edges[j].v] > dist[edges[j].u] + edges[j].w)
			return -1;	// negative-weight cycles exist.
	}
	return 0;			// negative-weight cycles don't exist.
}

int main(void)
{
	

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int i, j, TC;
	cin >> TC;

	// repeat as many Testcases
	for (i = 0; i < TC; i++) {
		cin >> NODES >> EDGES >> WORMS;
		EDGES = 2 * EDGES; // two-way street

		// two-way street, so make edges twice.
		for (j = 0; j < EDGES; j++) {
			cin >> edges[j].u >> edges[j].v >> edges[j].w;
			j++;
			// 방향성이 없으니 양쪽 모두 갈 수 있다고 생각하고 
			// 반대 방향으로도 edges[]에 집어넣음
			edges[j].u = edges[j - 1].v;
			edges[j].v = edges[j - 1].u;
			edges[j].w = edges[j - 1].w;
		}

		// one-way wormholes, so make edges once.
		// wormhole's weight is negative, so multiple -1.
		for (j = EDGES; j < EDGES + WORMS; j++) {
			cin >> edges[j].u >> edges[j].v >> edges[j].w;
			edges[j].w = edges[j].w * (-1);
		}

		// using Bellman-Ford algorithm
		if (BellmanFord() == -1)
			cout << "YES\n";	// if negative cycle exist, "YES\n"
		else
			cout << "NO\n";
	}
	return 0;
}