#include <iostream>
#include <vector>
using namespace std;

// vector graph
vector<int> graph[500001];

int ans = 0;
// Up-tree
// tree[i] : 정점 i의 부모
int tree[500001] = { 0 };

// tree[1] = 0; // 루트 노드는 0
// tree[4] = 1; // 정점 4의 부모 노드는 1
// tree[2] = 4; // 정점 2의 부모 노드는 4


void recursion(int j, int counts) {
	int sw = 0;
	for (int i = 0; i < graph[j].size(); i++) {
		if (tree[graph[j][i]] == 0 && graph[j][i] != 1) {
			sw++;
			tree[graph[j][i]] = j;
			recursion(graph[j][i], counts + 1);
		}
	}
	if (sw == 0) ans += counts;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, a, b;
	cin >> N;

	// 그래프가 만들어짐
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// top-down 방식
	// 루트 노드부터 탐색
	tree[1] = 1;
	int j = 1;
	recursion(1, 0);

	if (ans % 2 == 0) cout << "No";
	else cout << "Yes";

	return 0;
}
