#include <iostream>
using namespace std;

int arr[21];

int main(void)
{
	// 배열 초기화
	for (int i = 1; i <= 20; i++) {
		arr[i] = i;
	}

	int a, b;
	int temp[20];
	for (int i = 0; i < 10; i++) {
		cin >> a >> b; // 시작지점, 끝지점
		for (int j = a; j <= b; j++) {
			temp[j - a] = arr[j];
		}
		for (int j = 0; j <= b - a; j++) {
			arr[a + j] = temp[b - a - j];
		}
	}

	for (int i = 1; i <= 20; i++) {
		cout << arr[i] << " ";
	}
}