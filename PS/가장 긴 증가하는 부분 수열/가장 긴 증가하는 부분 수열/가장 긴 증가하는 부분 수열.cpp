#include <iostream>
using namespace std;

int arr[1001]; // 1 ~ 1000���� ����� ��
int P[1001]; // LIS������ ��ġ�� ��Ÿ��
int LIS[1001] = { 0, }; // 1 ~ 1000���� ����ϵ�, LIS[0] = 99999�� �ʱ�ȭ
int LIS_count = 0; // LIS�ȿ� ��ִ��� ����

int main(void)
{
	// �Է¹ޱ�
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	// ���� A�� ���� �� �����ϴ� �κ� ������ ���� ���
	// ��, ���� ���ڴ� ��ĥ �� ����
	LIS[0] = -111;
	for (int i = 1; i <= N; i++) {
		int sw = 0;
		for (int j = 0; j <= LIS_count; j++) {

			if (arr[i] <= LIS[j]) {
				LIS[j] = arr[i];
				P[i] = j;
				sw = 1;
				break;
			}

		}
		if (sw == 0) {
			LIS_count++;
			LIS[LIS_count] = arr[i];
			P[i] = LIS_count;
		}
	}
	/*
	for (int i = 1; i <= N; i++)
		cout << P[i] << " ";
	cout << "\n";

	for (int i = 1; i <= LIS_count; i++)
		cout << LIS[i] << " ";
	cout << "\n";
	*/
	cout << LIS_count;
	return 0;
}