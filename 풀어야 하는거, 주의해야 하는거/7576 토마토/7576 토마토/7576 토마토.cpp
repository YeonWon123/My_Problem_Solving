// queue의 개수가 너무 많이 잡히는 것이 문제!

#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> cases;

int arr[1001][1001];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int zero_case = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				cases.push({ i, j });
			}
			else if (arr[i][j] == 0)
				zero_case++;
		}
	}

	cases.push({ -1,-1 }); // 날짜가 바뀜을 의미함
	
	if (zero_case == 0) {
		cout << 0;
		return 0;
	}

	int day = 1, sw = 0;
	while (!cases.empty()) {
		int first = cases.front().first;
		int second = cases.front().second;

		cases.pop();
		if (first == -1 && second == -1) {
			if (sw == 1) {
				break;
			}
			cases.push({ -1, -1 });
			day++;
			sw = 1;
		}
		else {
			sw = 0;
		}

		for (int i = 0; i < 8; i++) {
			if (first + dy[i] < 0 || first + dy[i] >= N || second + dy[i] < 0 || second + dy[i] >= M) {
				continue;
			}
			else {
				if (arr[first + dy[i]][second + dx[i]] == 0) {
					arr[first + dy[i]][second + dx[i]] = 1;
					cases.push({ first + dy[i], second + dx[i] });
					zero_case--;
				}
			}
		}
	}

	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << day - 2;
	

	return 0;
}