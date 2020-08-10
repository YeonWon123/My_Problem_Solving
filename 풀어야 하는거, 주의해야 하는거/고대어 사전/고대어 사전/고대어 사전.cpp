#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

// �ڵ� 28.2 ���� ���� ������ �׷����� ����
// ���ĺ��� �� ���ڿ� ���� ���� ��� ǥ��
// ���� (i, j)�� ���ĺ� i�� j���� �տ� �;� ���� ��Ÿ����. ( i -> j)
vector<vector<int> > adj;
// �־��� �ܾ��κ��� ���ĺ� ���� ���İ��� �׷����� �����Ѵ�.
void makeGraph(const vector<string>& words) {
	// int adj[26][26] = { 0, } �� ������ �ڵ�
	// vector ������ : vector<�ڷ���>(���� ����, �ʱ�ȭ�� ���� ����)
	adj = vector<vector<int> >(26, vector<int>(26, 0));
	for (int j = 1; j < words.size(); ++j) {
		int i = j - 1, len = min(words[i].size(), words[j].size());
		// word[i]�� word[j] �տ� ���� ������ ã�´�.
		for (int k = 0; k < len; ++k) {
			if (words[i][k] != words[j][k]) {
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1; // a -> b
				break;
			}
		}
	}
}

// �ڵ� 28.3 ���� �켱 Ž���� �̿��� ���� ����
vector<int> seen, order;
void dfs(int here) {
	seen[here] = 1;
	for (int there = 0; there < adj.size(); ++there)
		if (adj[here][there] && !seen[there])
			dfs(there);
	order.push_back(here);
}

// adj�� �־��� �׷����� ���������� ����� ��ȯ�Ѵ�.
// �׷����� DAG�� �ƴ϶��, �� ���͸� ��ȯ�Ѵ�.
vector<int> topologicalSort() {
	int n = adj.size();
	seen = vector<int>(n, 0);
	order.clear();
	// Ž���ϸ鼭 order���ٰ� Ž�� ������ ����
	for (int i = 0; i < n; ++i) 
		if (!seen[i])	// ���� Ž���� ���� ���� ������
			dfs(i);		// dfs�� Ž���Ѵ�.
	reverse(order.begin(), order.end());	// Ž���� ������ �ݴ�� �����´�.
	// ���� �׷����� DAG�� �ƴ϶��, ���� ����� ������ ������ �ִ�. (����Ŭ�� �ִ�.)
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (adj[order[j]][order[i]])
				return vector<int>();
		}
	}
	// ���� �����, ���� �켱 Ž������ ���� ������ ��ȯ�Ѵ�.
	return order;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int C, N;
	string temp;
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N;
		vector<string> input;

		// �Է��� �޴´�.
		for (int j = 0; j < N; j++) {
			cin >> temp;
			input.push_back(temp);
		}

		// �׷����� �����.
		makeGraph(input);

		// �׷����� ���� ���� ������ �����Ѵ�.
		vector<int> res = topologicalSort();

/*
		for (int p = 0; p < res.size(); p++) {
			cout << res[p] << " ";
		}
		cout << "\n";
*/

		// ���� ������ ����� �� ���Ͱ� ������
		// ����Ŭ�� �־ ������ ���̴�.
		if (res.size() == 0) {
			cout << "INVALID HYPOTHESIS";
		}
		else {
			// �װ� �ƴ϶�� ���� ���� ������ ���缭 ���ĺ��� �������.
			for (int k = 0; k < res.size(); k++)
				cout << (char)(res[k] + 'a');
		}
		cout << "\n";
	}
	return 0;
}