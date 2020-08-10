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

// ���� ������ �ִ� ��� ��
int counts[200001] = { 0, };
// ���� ��Ӹ� �ϱ� �����ϴ� �ð�
int isRumor[200001] = { -1 };
// ���� �ð�
int time = -1;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// ���� ��Ӹ� �ϱ� �����ϴ� �ð��� -1�� �� �ʱ�ȭ
	// �̰� ������ ������Ʈ �ȵ� ����� ��Ӹ� �ȹ���
	memset(isRumor, -1, sizeof(isRumor));

	int N, M;
	cin >> N;

	// �Է¹޴� �κ�
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

		// ���� ���� �����̸� �̴� time�̴�.
		// ���� ���� time�� �־� �ش�.
		if (now < 0) {
			// queue�� ��� ������ �׳� ����
			if (q.empty()) break;
			time--;
			q.push(time);
			continue;
		}

		// �� ����� ��Ӹ� �ϴ��� ������Ʈ�� �ȵǾ����� (!= -1)
		// �� ����� �ʱ� �����ڰ� �ƴ϶�� (!= 0)
		if (isRumor[now] != -1 && isRumor[now] != 0) continue;
		isRumor[now] = (time + 1) * -1; // ���� ����!

		// ���� �������ִ� ������� ��
		for (int i = 0; i < graph[now].size(); i++) {
			n_count = 0;
			// ���� ������ �ִ� ����� ��Ӹ� ������? ���ʿ� ����
			if (isRumor[graph[now][i]] >= 0) continue;

			// �ȹ�����? �� ����� �ֺ� ����� �� 1/2 �̻��� ��Ӹ� �ϴ°�? Ȯ��
			for (int j = 0; j < graph[graph[now][i]].size(); j++) {
				if (isRumor[graph[graph[now][i]][j]] >= 0) n_count++;
			}

			// �ֺ����� ������ �Ѵ� �ο��� ��Ӹ� ������, �ڱ⵵ �Ͼ�� ��
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