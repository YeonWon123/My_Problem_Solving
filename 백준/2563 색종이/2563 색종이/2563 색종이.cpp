#include <iostream>
using namespace std;

// 실전에서는 주석 칠 시간이 많이 없을수도 있으니 주의!

// 가로, 세로의 크기가 각각 100인 정사각형 모양의 흰색 도화지
// 색종이가 도화지 밖으로 나가는 경우는 없음 -> 코너 체크 안해도 됨
// index는 1부터 100까지 사용할 예정 
int paper[101][101] = { 0, }; // 색칠되어 있으면 1, 아니면 0

int main(void) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		// 색종이는 10*10의 정사각형
		for (int j = a; j < a + 10; j++) {
			for (int k = b; k < b + 10; k++) {
				paper[j][k] = 1; // 색칠
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (paper[i][j] == 1)
				ans++;
		}
	}
	cout << ans;
	return 0;
}