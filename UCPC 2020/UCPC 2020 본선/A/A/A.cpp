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

long long ncount[100001] = { 0 };		// �������ִ� ��� ��
long long depth[100001] = { 0 };		// ��� ����
long long isvisit[100001] = { 0 };	// �湮 ����
vector<long long> graph[100001];		// �׷���, ������ �ִ� ��尡 ���� �� �� ����
queue<long long> q;					// BFS�� queue
queue<long long> res_leaf;			// �湮�ؾ� �ϴ� ���
vector<long long> res_adj;			// ��Ʈ ���, n_count >= 3�� ���

long long ans = 0;
long long N, S, D;

void DFS(long long node, long long n_depth, long long index) {
	if (((index == 0 && depth[node] <= n_depth)) && isvisit[node] == 0) {
		// ���� ���ؾ� �ϴ� ��, �� ������ ������ ���� ����
		res_leaf.push(node);
		isvisit[node] = 1;
		return;
	}
	for (long long i = 0; i < graph[node].size(); i++) {
		if (depth[graph[node][i]] < n_depth) DFS(graph[node][i], depth[graph[node][i]], index - 1);
	}
}

void DFS2(long long node, long long n_depth, long long dim) {
	// ��尡 res_adj�� �ִ��� Ȯ��
	auto it = std::find(res_adj.begin(), res_adj.end(), node);
	auto index = std::distance(res_adj.begin(), it);

	// ���� �ִٸ�, ���̸� ���ؼ� ans�� �����ְ� �Լ� ����
	if (it != res_adj.end() && dim != 0) {
		ans += dim;
		// ���� �� index�� ��Ʈ ��尡 �ƴϾ��ٸ� ť�� �߰�
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
	// �׷��� �����
	long long u, v;
	for (long long i = 0; i < N - 1; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);

		ncount[u]++; ncount[v]++;
	}

	// BFS�� depth ã�� �ֱ�
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

	// �� ��忡�� D��ŭ ������ ������ res_leaf�� �����ϱ�
	// ��Ʈ ����, ncount = 3�̻��� ������ res_adj�� �����ϱ�
	for (long long i = 1; i <= N; i++) {
		// �� ��忡�� D��ŭ ������ ��带 res_leaf�� ����
		if (ncount[i] == 1 && i != S) {
			DFS(i, depth[i], D);
		}
		else if (ncount[i] >= 3 || i == S) {
			res_adj.push_back(i);
		}
	}

	memset(isvisit, 0, sizeof(isvisit));

	// ���� : res_leaf�� �ִ� ������, depth�� �۾����� �������� ���� ����
	// ��ġ�� ������ ������ �ű���� ���ϰ� �� ��ġ�� ������ queue�� ������ ��
	long long dim = 0;
	while (!res_leaf.empty()) {
		dim = 0;
		now = res_leaf.front();
		res_leaf.pop();
	//	cout << now << " ";

		// ��ġ�� ������ ���� ������ or ���� ��尡 ���� ������ Ž��
		DFS2(now, depth[now], dim);
	}

	cout << ans * 2;


	return 0;
}