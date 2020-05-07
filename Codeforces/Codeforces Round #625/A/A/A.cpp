#include <iostream>
using namespace std;

int arr1[100] = { 0 };
int arr2[100] = { 0 };

int one_score = 0;
int two_score = 0;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	
	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
		if (arr1[i] > arr2[i]) {
			one_score++;
		}
		else if (arr1[i] < arr2[i]) {
			two_score++;
		}
	}
	
	// ���� arr1[i] > arr2[i] �� ���� ������ 0���̸� �Ұ���!
	// arr1[i] == arr2[i] �� ���� ������ don't care
	// arr1[i] < arr2[i] �� ���� ���� ���� ���ؼ�
	if (one_score == 0) cout << -1;
	else {
		int answer = two_score / one_score + 1;
		cout << answer;
	}

	return 0;
}