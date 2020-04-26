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

	// ��Ƽ�� �����ϴ� ������ Ÿ�Ӷ��� ����
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
	// �������� ģ������ �ҷ�����
	// friends[i][j] : ������ ģ���� i��ŭ j�ð��� �ҷ��� �� 
	// ��Ƽ�� �����Ǹ� 1, �ȵǸ� 0
	// ��, ������ ģ���� �� �ҷ��� ��Ƽ �����ϸ� ���� ��������
	int pos = 0; // ģ������ �� �ҷ��� ��Ƽ �����Ǵ� ���
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

	// friends[i][j]�� ��������� ������ ����
	// friends[i][j] == -1�� �Ǵ� �������� �������� 
	// �� �κк��� �����, �� �κп��� �� �� �ִ� �ִ� ��Ƽ ���� �ð��� �����Ѵ�.
	// friends_phase[i][j] : i��ŭ j�κп��� �������� �� �ִ� ��Ƽ ���� �ð�
	// �̸� ���� �� ���������� �������� friends[i][j]�� Ž���Ѵ�.
	// �׷��� �ð��� �������� ����ǰ� �ȴ�.
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

	// friends_phase�� �̿��ؼ� ���� ���� ���� ���� ����.
	// �κе��� ���� �ִ밡 �ǰԲ� �����ϵ�, 
	// friends_phase�� ���տ��� i�� ���� K�� ������ �� �ȴ�.
	// ���� �տ��� pos�� ���� �ξ��µ� �̰� ���������� ���� �־�� �Ѵ�.
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

	cout << "\n���� �� : ";
#endif
	cout << dp[index - 1][K] + pos << "\n";
	return 0;
}

