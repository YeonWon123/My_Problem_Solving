#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

long long p[100000];
long long m[100000];

int p_size;
int m_size;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long t, n, temp;
	cin >> t;
	while (t--) {
		p_size = 0; m_size = 0;

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			if (temp >= 0) {
				p[p_size] = temp;
				p_size++;
			}
			else {
				m[m_size] = temp;
				m_size++;
			}
		}
		sort(p, p + p_size, greater<>());
		sort(m, m + m_size);

		/*
		for (int i = 0; i < p_size; i++) {
			cout << p[i] << " ";
		}
		cout << "\n";

		for (int i = 0; i < m_size; i++) {
			cout << m[i] << " ";
		}
		cout << "\n";
		*/

		long long ltemp;
		long long ans = LLONG_MIN;

		if (p_size >= 5 && m_size >= 0) {
			ltemp = p[0] * p[1] * p[2] * p[3] * p[4];
		//	cout << ltemp << endl;
			ans = max(ltemp, ans);
		}

		if (p_size >= 4 && m_size >= 1) {
			ltemp = p[0] * p[1] * p[2] * p[3] * m[m_size-1];
		//	cout << ltemp << endl;
			ans = max(ltemp, ans);
		}

		if (p_size >= 3 && m_size >= 2) {
			ltemp = p[0] * p[1] * p[2] * m[0] * m[1];
			ans = max(ltemp, ans);
		//	cout << ltemp << endl;
		}

		if (p_size >= 2 && m_size >= 3) {
			ltemp = p[0] * p[1] * m[m_size - 1] * m[m_size - 2] * m[m_size - 3];
			ans = max(ltemp, ans);
		//	cout << ltemp << endl;
		}

		if (p_size >= 1 && m_size >= 4) {
			ltemp = p[0] * m[0] * m[1] * m[2] * m[3];
			ans = max(ltemp, ans);
		//	cout << ltemp << endl;
		}

		if (p_size >= 0 && m_size >= 5) {
			ltemp = m[m_size - 1] * m[m_size - 2] * m[m_size - 3] * m[m_size - 4] * m[m_size - 5];
			ans = max(ltemp, ans);
		//	cout << ltemp << endl;
		}

		cout << ans << "\n";

	}

	return 0;
}