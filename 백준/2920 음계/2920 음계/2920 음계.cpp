#include <iostream>
using namespace std;

int a[8];

int main(void)
{
	for (int i = 0; i < 8; i++) {
		cin >> a[i];
	}

	int i, j, k;

	// �������� �Ǵ�
	for (i = 0; i < 8; i++) {
		if (a[i] != i + 1) {
			break;
		}
	}

	// �������� �Ǵ�
	for (j = 0; j < 8; j++) {
		if (a[j] != 8 - j) {
			break;
		}
	}

	if (i == 8)
		cout << "ascending";
	else if (j == 8)
		cout << "descending";
	else
		cout << "mixed";

	return 0;
}