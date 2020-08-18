// 이걸 이해해야 한다...
// 왜 되는 거지?
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

	// 0 ~ 511까지 모두 시행? -> ??
	for (int i = 0; i < 512; ++i) {
		bool ok = 1;
		// 1부터 n까지 시행 -> 당연 (a[0] ~ a[n])
		for (int j = 1; j <= n; ++j) {
			bool flag = 0;
			// 1부터 m까지 시행 -> 당연 (b[0] ~ b[m])
			for (int k = 1; k <= m; ++k)
				// a[j]와 b[k]를 & 한 결과에 i를 &한 결과가
				// a[j] & b[k]와 동일한가?
				if (((a[j] & b[k]) & i) == (a[j] & b[k]))
					flag = 1;

			// 동일하지 않으면 ok = 0 and break?
			// 아 최소값을 이렇게 찾는구나
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
