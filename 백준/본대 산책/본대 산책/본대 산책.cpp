#include <iostream>
using namespace std;

// dp[횟수][장소] : "횟수" 시간동안 "장소"에 가는데 가능한 경우의 수
int dp[100001][8] = { 0, };

// 0 : 정보과학관, 1 : 전산관, 2 : 미래관, 3 : 신양관, 4 : 진리관, 5 : 한경직기념관, 6 : 학생회관, 7 : 형남공학관
// map[i][j] : i에서 j로 갈 수 없으면 0, 있으면 1
int map[8][8] = { {0, 1, 1, 0, 0, 0, 0, 0},
				  {1, 0, 1, 1, 0, 0, 0, 0},
				  {1, 1, 0, 1, 0, 1, 0, 0},
				  {0, 1, 1, 0, 1, 1, 0, 0},
				  {0, 0, 0, 1, 0, 1, 1, 0},
				  {0, 0, 1, 1, 1, 0, 0, 1},
				  {0, 0, 0, 0, 1, 0, 0, 1},
				  {0, 0, 0, 0, 0, 1, 1, 0}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int D;
	cin >> D;

	// dp[1][전산관] = 1, dp[1][미래관] = 1, 나머지는 0;
	// dp[2][정보과학관] = dp[1][전산관] + dp[1][미래관]
	// dp[2][전산관] = dp[1][정보과학관] + dp[1][미래관] + dp[1][신양관]
	dp[1][1] = 1;
	dp[1][2] = 1;
	for (int i = 2; i <= D; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				if (map[j][k] == 1) {
					dp[i][j] += dp[i - 1][k];
					dp[i][j] %= 1000000007;
				}
			}
		}
	}

	cout << dp[D][0];
}