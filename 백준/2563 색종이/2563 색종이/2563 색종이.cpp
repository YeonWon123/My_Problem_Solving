#include <iostream>
using namespace std;

// ���������� �ּ� ĥ �ð��� ���� �������� ������ ����!

// ����, ������ ũ�Ⱑ ���� 100�� ���簢�� ����� ��� ��ȭ��
// �����̰� ��ȭ�� ������ ������ ���� ���� -> �ڳ� üũ ���ص� ��
// index�� 1���� 100���� ����� ���� 
int paper[101][101] = { 0, }; // ��ĥ�Ǿ� ������ 1, �ƴϸ� 0

int main(void) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		// �����̴� 10*10�� ���簢��
		for (int j = a; j < a + 10; j++) {
			for (int k = b; k < b + 10; k++) {
				paper[j][k] = 1; // ��ĥ
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