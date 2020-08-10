#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> now;

int n;
int dy[6] = { 2, -2, 1, 1, -1, -1 };
int dx[6] = { 0, 0, -1, 1, -1, 1 };
long long ans = 0;

// dir : 방향
int dir[6][2] = { {2,3}, {4,5}, {0,4}, {0,5}, {1,2}, {1,3} };

/*
 방향
 0 -> 2, 3 
 1 -> 4, 5
 2 -> 0, 4
 3 -> 0, 5
 4 -> 1, 2
 5 -> 1, 3
*/

bool isMeeting(int y, int x) {
	for (int i = 0; i < now.size(); i++) {
		if (now[i].first == y && now[i].second == x) return true;
	}
	return false;
}

void recursion(int y, int x, int d, int count) {
	if (count == n) {
		if (isMeeting(y, x))
			ans++;
		return;
	}
	else {
		// count도 아닌데 중간에 만났으면 이건 답이 아니다.
		if (isMeeting(y, x))
			return;
	}

	now.push_back({ y, x });

	for (int i = 0; i < 2; i++) {
		recursion(y + dy[dir[d][i]], x + dx[dir[d][i]], dir[d][i], count + 1);
	}

	now.pop_back();
}

int main(void)
{
	cin >> n;
	now.push_back({ 0,0 });
	recursion(2, 0, 0, 0);
	cout << ans;

	return 0;
}