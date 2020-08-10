#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int isvisit[100001];
vector<int> graph[100001];
long long ans = 0;
int N, S, D;
queue<int> q;

void DFS0(int node) {
	isvisit[node] = 1;

	for (int i = 0; i < graph[node].size(); i++) {
		if (isvisit[graph[node][i]] == 0) {
			ans++;
			isvisit[graph[node][i]] = 1;
			DFS0(graph[node][i]);
		}
	}
}

int n_counts = 0;
void DFS1(int node, int weight) {
	isvisit[node] = 1;

	if (weight == D && graph[node].size() > 1) {
		// 새로 탐색해야 하는 지점을 구함
		q.push(node);
		n_counts++;
	}

	for (int i = 0; i < graph[node].size(); i++) {
		if (isvisit[graph[node][i]] == 0) {
			isvisit[graph[node][i]] = 1;
			DFS1(graph[node][i], weight + 1);
		}
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> S >> D;

	int x, y;
	for (int i = 0; i < N - 1; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	memset(isvisit, 0, sizeof(isvisit));
	n_counts = 0;

	// D가 0이면? -> DFS로 다 구할 수 있음 ㄱㄱ
	if (D == 0) DFS0(S);
	else {
		// D가 0이 아닌 경우 일단 한번에 갈 수 있는 지점은 ㄱㄱ
		// 그런 뒤 D를 이동시키면서, 그때마다 큐에서 불러와서 사용
		int now;
		if (!q.empty()) {
			DFS1(S, 0);
			ans++;
			q.push(-1);
		}
		while (!q.empty()) {
			now = q.front();
			q.pop();
			if (now < 0 && q.empty()) break;
			else {
				q.push(-1);
				ans++;
			}

			DFS1(now, 0);
		}
	}
	cout << ans * 2;

	return 0;
}