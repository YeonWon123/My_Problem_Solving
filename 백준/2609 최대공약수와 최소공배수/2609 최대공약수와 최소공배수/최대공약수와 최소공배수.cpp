#include <iostream>
#include <numeric>
using namespace std;

// �ִ�����
// ��Ŭ���� ȣ���� �̿�
int gcd(int a, int b) {
	if (a < b)
		swap(a, b);

	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

// �ּҰ����
// �տ��� ���� �ִ������� �̿�
// �������� ���� �Ͽ� �����÷ο� ����
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int main(void)
{
	int a, b;
	cin >> a >> b;

	// cout << gcd(a, b) << "\n" << lcm(a, b);
	return 0;
}