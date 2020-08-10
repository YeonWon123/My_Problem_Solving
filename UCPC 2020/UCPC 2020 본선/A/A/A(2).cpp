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

long long isFull[100001] = { 0 };
vector<long long> graph[100001];
queue<long long> q;

long long ans = 0;
long long N, S, D;

void visit(long long node, long long distance) {
	isFull[node]++;
	if (distance < 0) {
		return;
	}

	// 현재 내 노드와 인접해 있는 노드에 색칠, 단 distance==0 이면 색칠하지 않음
	for (long long j = 0; j < graph[node].size(); j++) {
		// 아직 방문하지 않았다면 방문
		if (isFull[graph[node][j]] == 0) {
			if (distance != 0) {
				isFull[graph[node][j]] = 1;
				visit(graph[node][j], distance - 1);
			}
			else {
			//	cout << graph[node][j] << endl;
			//	cout << "ans추가" << endl;
				q.push(graph[node][j]);
				if (D == 0) ans += 1;
				else ans += D;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S >> D;
	q.push(S);

	int u, v;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	long long now;
	while (!q.empty()) {
		now = q.front();
		q.pop();

		// 거리가 D에 해당하는 모든 노드에 색칠
		visit(now, D);
	}
	cout << ans * 2;

	return 0;
}