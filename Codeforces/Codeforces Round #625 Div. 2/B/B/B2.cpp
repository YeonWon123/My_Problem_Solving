#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> result[200000];

int counts = 0;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		result[i].first = temp - i;
		result[i].second = temp;
	}

	// result[i].first의 값이 같은것끼리 비교함
	sort(result, result + n);

	long long answer = 0;
	int first = result[0].first;
	long long temp2 = result[0].second;
	for (int i = 1; i < n; i++) {
		if (result[i].first == first) {
			temp2 = temp2 + result[i].second;
		}
		else {
			if (answer < temp2) {
				answer = temp2;
			}
			temp2 = result[i].second;
			first = result[i].first;
		}
	}
	if (answer < temp2)
		answer = temp2;

	cout << answer;
	return 0;
}