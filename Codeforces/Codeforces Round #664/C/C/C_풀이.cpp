// �̰� �����ؾ� �Ѵ�...
// �� �Ǵ� ����?
#include <iostream>
using namespace std;
int n, m;
int a[233], b[233];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i)
		cin >> b[i];

	// 0 ~ 511���� ��� ����? -> ??
	for (int i = 0; i < 512; ++i) {
		bool ok = 1;
		// 1���� n���� ���� -> �翬 (a[0] ~ a[n])
		for (int j = 1; j <= n; ++j) {
			bool flag = 0;
			// 1���� m���� ���� -> �翬 (b[0] ~ b[m])
			for (int k = 1; k <= m; ++k)
				// a[j]�� b[k]�� & �� ����� i�� &�� �����
				// a[j] & b[k]�� �����Ѱ�?
				if (((a[j] & b[k]) & i) == (a[j] & b[k]))
					flag = 1;

			// �������� ������ ok = 0 and break?
			// �� �ּҰ��� �̷��� ã�±���
			if (!flag) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
