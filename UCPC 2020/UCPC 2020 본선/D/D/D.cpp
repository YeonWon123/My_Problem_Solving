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

int arr[300001] = { 0 };
vector<int> graph[300001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	int u, v;
	int two = 0;
	long long ans1 = 0;	// ㄷ
	long long ans2 = 0;	// ㅈ
	for (int i = 0; i < N-1; i++) {
		cin >> u >> v;
		if (u < v) graph[u].push_back(v);
		else graph[v].push_back(u);

		arr[u]++; arr[v]++;
	}

	for (int i = 1; i <= N; i++) {
		// cout << arr[i] << " ";
		// ㅈ트리 개수 누적
		if (arr[i] >= 3) {
			ans2 += (long long)arr[i] * (arr[i] - 1) / 2 * (arr[i] - 2);
		}
	}

	// ㄷ트리 개수 누적
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			//cout << "계산한 ㄷ트리 개수 : " << i << " " << j << endl << arr[i] - 1 << " " << arr[graph[i][j]] - 1 << endl;
			//cout << (long long)(arr[i] - 1) * (arr[graph[i][j]] - 1);
			ans1 += (long long)(arr[i] - 1) * (arr[graph[i][j]] - 1);
		}
		//cout << endl;
	}
		



	// cout << ans1 << " " << ans2 << endl;
	
	if (ans1 < ans2) {
		cout << "G";
	}
	else if (ans1 > ans2) {
		cout << "D";
	}
	else
		cout << "DUDUDUNGA";

	return 0;
}