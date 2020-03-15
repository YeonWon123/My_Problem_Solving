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
	
	// 만약 arr1[i] > arr2[i] 한 것의 개수가 0개이면 불가능!
	// arr1[i] == arr2[i] 인 것의 개수는 don't care
	// arr1[i] < arr2[i] 인 것의 개수 역시 구해서
	if (one_score == 0) cout << -1;
	else {
		int answer = two_score / one_score + 1;
		cout << answer;
	}

	return 0;
}