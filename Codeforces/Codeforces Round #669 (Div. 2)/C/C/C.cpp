#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int a[10001];

// ������ �ϰ� ������ �޴� �κ�
// ���� : "? x y"
// ��� : k
int query(int x, int y) {
	cout << "? " << x << ' ' << y << "\n";
	cin >> x;
	return x;
}

int main(void)
{
//  �� ���������� ���� ������ �߻��Ѵ�.
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	// two pointer ����� �����ϰ� �Ѵ�.
	// p = 1, i = 2���� Ž�� ����
	// p�� �������� -> p = i, i = i + 1
	// i�� �������� -> p = p, i = i + 1
	int p = 1;
	for (int i = 2; i <= n; i++) {
		int v1 = query(i, p);
		int v2 = query(p, i);
		
		// ���� : a % b ���� b % a�� ū ��� : b < a�̸� a = b % a�� �ȴ�.
		// ���� : a % b ���� b % a�� ���� ��� : b > a�̸� b = b % a�� �ȴ�.
		// ���� : a % b�� b % a�� ���� ��� : ������ �� ����. (a != b�̱� ����)
		if (v1 < v2) a[p] = v2, p = i;
		else a[i] = v1;
	}
	// ������ ���� ���ڸ��� n�� �Ǿ�� �Ѵ�.
	a[p] = n;

	cout << "!";
	for (int i = 1; i <= n; i++) {
		cout << " " << a[i];
	}
	fflush(stdout);

	return 0;
}