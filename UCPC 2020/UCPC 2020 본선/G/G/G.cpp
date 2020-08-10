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

vector<int> graph[200001];
queue<int> q;

// 나랑 인접해 있는 노드 수
int counts[200001] = { 0, };
// 내가 루머를 믿기 시작하는 시간
int isRumor[200001] = { -1 };
// 현재 시간
int time = -1;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 내가 루머를 믿기 시작하는 시간을 -1로 다 초기화
	// 이게 끝까지 업데이트 안된 사람은 루머를 안믿음
	memset(isRumor, -1, sizeof(isRumor));

	int N, M;
	cin >> N;

	// 입력받는 부분
	int a;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		while (a != 0) {
			counts[i]++;
			graph[i].push_back(a);
			cin >> a;
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a;
		isRumor[a] = 0;
		q.push(a);
	}

	q.push(time);
	int now, n_count;
	while (!q.empty()) {
		now = q.front();
		q.pop();

		// 뽑은 값이 음수이면 이는 time이다.
		// 따라서 다음 time을 넣어 준다.
		if (now < 0) {
			// queue가 비어 있으면 그냥 나감
			if (q.empty()) break;
			time--;
			q.push(time);
			continue;
		}

		// 이 사람이 루머를 믿는지 업데이트가 안되었으면 (!= -1)
		// 이 사람이 초기 유포자가 아니라면 (!= 0)
		if (isRumor[now] != -1 && isRumor[now] != 0) continue;
		isRumor[now] = (time + 1) * -1; // 지금 수행!

		// 나랑 인접해있는 사람들을 봄
		for (int i = 0; i < graph[now].size(); i++) {
			n_count = 0;
			// 나랑 인접해 있는 사람이 루머를 믿으면? 볼필요 없음
			if (isRumor[graph[now][i]] >= 0) continue;

			// 안믿으면? 그 사람의 주변 사람들 중 1/2 이상이 루머를 믿는가? 확인
			for (int j = 0; j < graph[graph[now][i]].size(); j++) {
				if (isRumor[graph[graph[now][i]][j]] >= 0) n_count++;
			}

			// 주변인의 절반이 넘는 인원이 루머를 믿으면, 자기도 믿어야 함
			if (n_count * 2 >= graph[graph[now][i]].size()) {
				q.push(graph[now][i]);
			}
		}


	}

	for (int i = 1; i <= N; i++) {
		cout << isRumor[i] << " ";
	}

	return 0;
}