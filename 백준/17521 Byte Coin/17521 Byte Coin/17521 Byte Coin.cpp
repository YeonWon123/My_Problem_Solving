#include <iostream>
using namespace std;

int arr[20];
int dp[20] = { 0 }; // ��� �ϴ� ���� : 1, �Ⱦƾ� �ϴ� ���� : 2
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	long long W;
	long long b_c = 0;
	cin >> n >> W;

	// -1 : �������� ����
	// 0 : ó��
	// 1 : �������� ����
	int sw = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i != 0) {
			// �����ϴ� ���� -> �ִ��� ���� �Ĵ� ������ �� �� ����
			if ((sw == 0 || sw == -1) && (arr[i] > arr[i - 1])) {
				// arr[i-1]�� �������� �ִ��� ���� ��� ��.
				b_c += W / arr[i-1];
				W -= W / arr[i-1] * arr[i-1];

			//	dp[i-1] = 1;
				sw = 1;
			}
			// �����ϴ� ���� -> �ִ��� ���� ��� ������ �� �� ����
			else if ((sw == 0 || sw == 1) && (arr[i] < arr[i - 1])) {
				// arr[i-1]�� �������� �ִ��� ���� ��� ��.
				W += (long long)b_c * arr[i - 1];
				b_c = 0;

			//	dp[i-1] = 2;
				sw = -1;
			}
		}

		// ���� ���� ������ �����̰� ���� ���̶��
		// ������ ���� �� �� �Ǵ�.
		if (i == n-1 && sw == 1) {
			W += (long long)b_c * arr[i];
			b_c = 0;
		//	dp[i - 1] = 1;
		}
		// cout << i + 1 << "�� �� W : " << W << endl;
	}

	cout << W;

	return 0;
}