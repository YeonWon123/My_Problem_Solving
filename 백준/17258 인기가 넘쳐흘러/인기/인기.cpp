#define DEBUG

#include <iostream>
#include <algorithm>
using namespace std;

int party[400] = { 0, };
int friends[400][400] = { -1, };
int friends_phase[400][400] = { 0, };
int dp[400][400] = { 0, };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 파티에 참가하는 참가자 타임라인 종합
	int N, M, K, T;
	cin >> N >> M >> K >> T;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		for (int j = a - 1; j <= b - 2; j++) {
			party[j] += 1;
		}
	}
#ifdef DEBUG
	for (int i = 0; i < N; i++) {
		cout << party[i] << "\t";
	}
	cout << "\n\n";
#endif
	// 영선이의 친구들을 불러보자
	// friends[i][j] : 영선이 친구를 i만큼 j시간에 불렀을 때 
	// 파티가 만족되면 1, 안되면 0
	// 단, 영선이 친구들 안 불러도 파티 만족하면 따로 생각하자
	int pos = 0; // 친구들을 안 불러도 파티 성립되는 경우
	for (int i = 0; i <= K; i++) {
		for (int j = 0; j < N; j++) {
			if (party[j] >= T) {
				friends[i][j] = -1;
				if (i == 0) pos++;
				continue;
			}
			if (party[j] + i >= T) {
				friends[i][j] = 1;
			}
			else
				friends[i][j] = 0;
		}
	}
#ifdef DEBUG
	for (int i = 0; i <= K; i++) {
		for (int j = 0; j < N; j++) {
			cout << friends[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << endl << pos << endl << endl;
#endif

	// friends[i][j]를 만들었으니 정리해 보자
	// friends[i][j] == -1이 되는 지점들을 기준으로 
	// 각 부분별로 나누어서, 각 부분에서 낼 수 있는 최대 파티 지속 시간을 저장한다.
	// friends_phase[i][j] : i명만큼 j부분에서 투입했을 때 최대 파티 지속 시간
	// 이를 위해 맨 끝에서부터 역순으로 friends[i][j]를 탐색한다.
	// 그러면 시간의 역순으로 저장되게 된다.
	int now, index = 0;
	for (int i = 0; i <= K; i++) {
		now = 0; index = 0;
		for (int j = N - 1; j > -1; j--) {
			if (now != -1 && friends[i][j] != -1)
				now += friends[i][j];
			else if (now != -1 && friends[i][j] == -1) {
				friends_phase[i][index] = now;
				now = -1;
				index++;
			}
			else if (now == -1 && friends[i][j] != -1) {
				now = friends[i][j];
			}
		}
		if (now != -1) {
			friends_phase[i][index] = now;
			index++;
		}
	}
#ifdef DEBUG
	for (int i = 0; i <= K; i++) {
		for (int j = 0; j < index; j++) {
			cout << friends_phase[i][j] << "\t";
		}
		cout << "\n";
	}

	cout << "\n";
#endif

	// friends_phase를 이용해서 이제 최종 답을 구해 보자.
	// 부분들의 합이 최대가 되게끔 구성하되, 
	// friends_phase의 조합에서 i의 합이 K를 넘으면 안 된다.
	// 또한 앞에서 pos를 따로 두었는데 이걸 최종적으로 더해 주어야 한다.
	// dp[i][j] = max(dp[i-1][t] + friend_phase[i][j-t])
	int answer = 0;
	for (int i = 0; i < index; i++) {
		for (int j = 0; j <= K; j++) {
			if (i == 0) {
				dp[i][j] = friends_phase[j][i];
			}
			else {
				for (int t = 0; t <= j; t++) {
					dp[i][j] = max(dp[i][j], dp[i - 1][t] + friends_phase[j - t][i]);
				}
			}
		}
	}
#ifdef DEBUG
	for (int i = 0; i < index; i++) {
		for (int j = 0; j <= K; j++) {
			cout << dp[i][j] << "\t";
		}
		cout << "\n";
	}

	cout << "\n최종 답 : ";
#endif
	cout << dp[index - 1][K] + pos << "\n";
	return 0;
}

