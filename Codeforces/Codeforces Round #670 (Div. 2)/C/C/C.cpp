#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> tree[100001];
long long counts[100001];


queue<int> q;
int visited[100001];
int BFS(int j, int i) {
	int f; int res = 0;
	visited[i] = 1;
	visited[j] = 1;
	q.push(j);
	while (!q.empty()) {
		f = q.front();
		q.pop();
		res++;
		for (int i = 0; i < tree[f].size(); i++) {
			if (visited[tree[f][i]] != 1) {
				visited[tree[f][i]] = 1;
				q.push(tree[f][i]);
			}
		}
	}
	return res;
}

// 나에게 연결되어 있는 정점을 기준으로 BFS 탐색을 시행해서 크기를 구한다.
// 이 크기의 max가 min이 되는 점이 centroid이며 1개 ~ 2개가 나올 수 있다.
// 2개보다 많이 나올 수 없다.
void centroid(int n) {
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		cout << "정점 " << i << "의 centroid 구하기 위함" << endl;
		for (int j = 0; j < tree[i].size(); j++) {
			cout << BFS(tree[i][j], i) << " ";
		}
		cout << "\n";
	}
	exit(0);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, x, y;

	cin >> t;
	while (t--) {
		for (int i = 1; i <= 100000; i++) {
			tree[i].clear();
			counts[i] = 0;
		}

		int max_value = 0;
		int max_index = -1;
		int leaf = -1;

		cin >> n;
		for (int i = 0; i < n - 1; i++) {
			cin >> x >> y;
			tree[x].push_back(y);
			tree[y].push_back(x);

			counts[x]++;
			counts[y]++;
		}

		centroid(n);

		int pos;
		// max_index 노드 구하기
		for (pos = 1; pos <= n; pos++) {

			if (counts[pos] == max_value)
				max_index = pos;
			
		}

		// leaf 노드 구하기
		int l_leaf = -1;
		for (pos = 1; pos <= n; pos++) {
			if (counts[pos] == 1) {
				// 내 노드 바로 위가 max_index이면 안됨!
				int sw = 0;
				for (int i = 0; i < tree[pos].size(); i++) {
					if (tree[pos][i] == max_index) {
					//	cout << "들킴" << pos << " " << tree[pos][i] << " " << endl;
						l_leaf = pos;
						sw = 1; break;
					}
				}
				if (sw == 0) {
					leaf = pos;
					break;
				}
			}
		}

		// cout << leaf << " " << l_leaf << " " << max_index << endl;
		if (leaf == -1) {
			cout << max_index << " " << l_leaf << "\n";
			cout << max_index << " " << l_leaf << "\n";
		}
		else {
			// 잎 노드를 가장 많은 곳에 붙인다. 단 그 잎노드는 연관되면 안됨
			cout << tree[leaf][0] << " " << leaf << "\n";
			cout << leaf << " " << max_index << "\n";
		}
	}


}