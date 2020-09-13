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

// ������ ����Ǿ� �ִ� ������ �������� BFS Ž���� �����ؼ� ũ�⸦ ���Ѵ�.
// �� ũ���� max�� min�� �Ǵ� ���� centroid�̸� 1�� ~ 2���� ���� �� �ִ�.
// 2������ ���� ���� �� ����.
void centroid(int n) {
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		cout << "���� " << i << "�� centroid ���ϱ� ����" << endl;
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
		// max_index ��� ���ϱ�
		for (pos = 1; pos <= n; pos++) {

			if (counts[pos] == max_value)
				max_index = pos;
			
		}

		// leaf ��� ���ϱ�
		int l_leaf = -1;
		for (pos = 1; pos <= n; pos++) {
			if (counts[pos] == 1) {
				// �� ��� �ٷ� ���� max_index�̸� �ȵ�!
				int sw = 0;
				for (int i = 0; i < tree[pos].size(); i++) {
					if (tree[pos][i] == max_index) {
					//	cout << "��Ŵ" << pos << " " << tree[pos][i] << " " << endl;
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
			// �� ��带 ���� ���� ���� ���δ�. �� �� �ٳ��� �����Ǹ� �ȵ�
			cout << tree[leaf][0] << " " << leaf << "\n";
			cout << leaf << " " << max_index << "\n";
		}
	}


}