#include <iostream>	
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first)
		return a.first < b.first;
	else
		return a.second < b.second;
}

vector<pair<int, int>> point;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	int a, b;
	long long min_value, max_value;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		point.push_back({ a,b });
	}

	sort(point.begin(), point.end(), comp);
	min_value = point[0].first;
	max_value = point[0].second;
	long long answer = 0;
	for (int i = 1; i < N; i++) {
		if (max_value < point[i].first) {
			answer += (long long)max_value - min_value;
			min_value = point[i].first;
			max_value = point[i].second;
		}
		else {
			if (max_value < point[i].second)
				max_value = point[i].second;
		}
	//	cout << point[i].first << " " << point[i].second << "\n";
	//	cout << answer << endl;
	}

	answer += (long long)max_value - min_value;
	cout << answer;
	return 0;
}