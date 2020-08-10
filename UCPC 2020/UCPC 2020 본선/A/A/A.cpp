// #include <bits/stdc++.h>
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

long long ncount[100001] = { 0 };		// 인접해있는 노드 수
long long depth[100001] = { 0 };		// 노드 깊이
long long isvisit[100001] = { 0 };	// 방문 여부
vector<long long> graph[100001];		// 그래프, 인접해 있는 노드가 뭔지 알 수 있음
queue<long long> q;					// BFS용 queue
queue<long long> res_leaf;			// 방문해야 하는 노드
vector<long long> res_adj;			// 루트 노드, n_count >= 3인 노드

long long ans = 0;
long long N, S, D;

void DFS(long long node, long long n_depth, long long index) {
	if (((index == 0 && depth[node] <= n_depth)) && isvisit[node] == 0) {
		// 내가 구해야 하는 것, 단 이전에 했으면 넣지 않음
		res_leaf.push(node);
		isvisit[node] = 1;
		return;
	}
	for (long long i = 0; i < graph[node].size(); i++) {
		if (depth[graph[node][i]] < n_depth) DFS(graph[node][i], depth[graph[node][i]], index - 1);
	}
}

void DFS2(long long node, long long n_depth, long long dim) {
	// 노드가 res_adj에 있는지 확인
	auto it = std::find(res_adj.begin(), res_adj.end(), node);
	auto index = std::distance(res_adj.begin(), it);

	// 만약 있다면, 길이를 구해서 ans에 더해주고 함수 종료
	if (it != res_adj.end() && dim != 0) {
		ans += dim;
		// 만약 그 index가 루트 노드가 아니었다면 큐에 추가
		if (index != S) res_adj.push_back(index);
		return;
	}

	for (long long i = 0; i < graph[node].size(); i++) {
		if (depth[graph[node][i]] < n_depth) DFS2(graph[node][i], depth[graph[node][i]], dim + 1);
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S >> D;
	q.push(S);
	q.push(-1);
	//res_adj.push_back(S);
	// 그래프 만들기
	long long u, v;
	for (long long i = 0; i < N - 1; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);

		ncount[u]++; ncount[v]++;
	}

	// BFS로 depth 찾아 넣기
	long long now, n_depth = 0;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		if (now == -1) {
			if (q.empty()) break;
			else q.push(-1);
			n_depth++;
			continue;
		}
		isvisit[now] = 1;
		depth[now] = n_depth;
		for (long long i = 0; i < graph[now].size(); i++) {
			if (isvisit[graph[now][i]] == 0) q.push(graph[now][i]);
		}
	}

	memset(isvisit, 0, sizeof(isvisit));

	// 잎 노드에서 D만큼 떨어진 노드들을 res_leaf에 저장하기
	// 루트 노드와, ncount = 3이상인 노드들을 res_adj에 저장하기
	for (long long i = 1; i <= N; i++) {
		// 잎 노드에서 D만큼 떨어진 노드를 res_leaf에 저장
		if (ncount[i] == 1 && i != S) {
			DFS(i, depth[i], D);
		}
		else if (ncount[i] >= 3 || i == S) {
			res_adj.push_back(i);
		}
	}

	memset(isvisit, 0, sizeof(isvisit));

	// 최종 : res_leaf에 있는 노드들을, depth가 작아지는 방향으로 길이 구함
	// 겹치는 구간이 나오면 거기까지 구하고 그 겹치는 구간을 queue에 넣으면 됨
	long long dim = 0;
	while (!res_leaf.empty()) {
		dim = 0;
		now = res_leaf.front();
		res_leaf.pop();
	//	cout << now << " ";

		// 겹치는 구간이 나올 때까지 or 루프 노드가 나올 때까지 탐색
		DFS2(now, depth[now], dim);
	}

	cout << ans * 2;


	return 0;
}