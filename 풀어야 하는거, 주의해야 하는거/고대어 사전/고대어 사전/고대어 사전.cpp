#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

// 코드 28.2 고대어 사전 문제의 그래프를 생성
// 알파벳의 각 글자에 대한 인접 행렬 표현
// 간선 (i, j)는 알파벳 i가 j보다 앞에 와야 함을 나타낸다. ( i -> j)
vector<vector<int> > adj;
// 주어진 단어들로부터 알파벳 간의 선후관계 그래프를 생성한다.
void makeGraph(const vector<string>& words) {
	// int adj[26][26] = { 0, } 와 동일한 코드
	// vector 생성자 : vector<자료형>(원소 개수, 초기화를 뭘로 할지)
	adj = vector<vector<int> >(26, vector<int>(26, 0));
	for (int j = 1; j < words.size(); ++j) {
		int i = j - 1, len = min(words[i].size(), words[j].size());
		// word[i]가 word[j] 앞에 오는 이유를 찾는다.
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

// 코드 28.3 깊이 우선 탐색을 이용한 위상 정렬
vector<int> seen, order;
void dfs(int here) {
	seen[here] = 1;
	for (int there = 0; there < adj.size(); ++there)
		if (adj[here][there] && !seen[there])
			dfs(there);
	order.push_back(here);
}

// adj에 주어진 그래프를 위상정렬한 결과를 반환한다.
// 그래프가 DAG가 아니라면, 빈 벡터를 반환한다.
vector<int> topologicalSort() {
	int n = adj.size();
	seen = vector<int>(n, 0);
	order.clear();
	// 탐색하면서 order에다가 탐색 순서를 저장
	for (int i = 0; i < n; ++i) 
		if (!seen[i])	// 아직 탐색을 안한 점이 있으면
			dfs(i);		// dfs로 탐색한다.
	reverse(order.begin(), order.end());	// 탐색한 순서를 반대로 뒤집는다.
	// 만약 그래프가 DAG가 아니라면, 정렬 결과에 역방향 간선이 있다. (사이클이 있다.)
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (adj[order[j]][order[i]])
				return vector<int>();
		}
	}
	// 없는 경우라면, 깊이 우선 탐색에서 얻은 순서를 반환한다.
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

		// 입력을 받는다.
		for (int j = 0; j < N; j++) {
			cin >> temp;
			input.push_back(temp);
		}

		// 그래프를 만든다.
		makeGraph(input);

		// 그래프에 대한 위상 정렬을 수행한다.
		vector<int> res = topologicalSort();

/*
		for (int p = 0; p < res.size(); p++) {
			cout << res[p] << " ";
		}
		cout << "\n";
*/

		// 위상 정렬의 결과로 빈 벡터가 나오면
		// 사이클이 있어서 실패한 것이다.
		if (res.size() == 0) {
			cout << "INVALID HYPOTHESIS";
		}
		else {
			// 그게 아니라면 위상 정렬 순서에 맞춰서 알파벳을 출력하자.
			for (int k = 0; k < res.size(); k++)
				cout << (char)(res[k] + 'a');
		}
		cout << "\n";
	}
	return 0;
}