#include <iostream>
using namespace std;

int arr[1001];

int main(void)
{
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		arr[i] = i;
	}

	cout << "<";
	// N�� ���� - N���� ����� ��� ���ŵ� ������
	int index = 1;
	for (int i = 1; i <= N; i++) {
		// K�� ���� - K��° ����� ����
		for (int j = 1; j < K; j++) {
			while (arr[index] == -1) {
				index++;
				if (index > N) index = 1;
			}
			index++;
			if (index > N) index = 1;
		}

		while (arr[index] == -1) {
			index++;
			if (index > N) index = 1;
		}
	//	cout << endl << "d : " << index << endl;
		cout << arr[index];
		arr[index] = -1;
		index++;
		if (index > N) index = 1;
		if (i != N) cout << ", ";
	}
	cout << ">";
	return 0;
}