#include <iostream>
#include <algorithm>
using namespace std;

// roll[i][j][k] : 첫번째 주사위 눈은 i, 두번째 주사위 눈은 j, 세번째 주사위 눈은 k일때 얻는 상금
int roll[6][6][6];
int n_sum = 0; // roll[i][j][k]의 총 합

// DP[i] : i번째로 주사위를 던졌을 때, 나올 수 있는 모든 상금의 합
// DP[i] = DP[i-1] + n_sum*6^(i-3)
// ans = DP[i] * 1/(6*6*6 + 6*6*6*6 + 6*6*6*6*6 + ...)을 하면 된다.
// 왜냐면, N이 5라고 하면, 주사위는 3번, 4번, 5번 던지는 것이 모두 가능하기 때문이다.

int main(void)
{
	int N;
	cin >> N;

	// roll 배열 초기화
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 6; k++) {
				// 같은 눈이 3개 나오는 경우
				if (i == j && j == k) {
					roll[i][j][k] = 10000 + i * 1000;
				}
				// 같은 눈이 2개 나오는 경우
				else if (i == j || j == k || k == i) {
					int temp;
					if (i == j) temp = i;
					else if (j == k) temp = j;
					else temp = k;
					roll[i][j][k] = 1000 + temp * 100;
				}
				// 모두 다른 눈인 경우
				else {
					int temp = max(i, max(j, k));
					roll[i][j][k] = temp * 100;
				}
			}
		}
	}

	// for문을 돌면서 DP 배열을 채워야 함


}