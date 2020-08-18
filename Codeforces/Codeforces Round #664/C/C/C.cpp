#define DEBUG

#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <bitset>
using namespace std;

set<int> a;
set<int> b;

int valu[200][200];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, temp;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.insert(temp);
	}

	for (int i = 0; i < m; i++) {
		cin >> temp;
		b.insert(temp);
	}

	set<int>::reverse_iterator iter1;
	set<int>::iterator iter2;
	int a11, b11, c11;
	int min_v = 0;
	int ans = 0;
	for (iter1 = a.rbegin(); iter1 != a.rend(); ++iter1) {
		min_v = 1111111111;
		a11 = *iter1;
#ifdef DEBUG
		cout << bitset<10>(a11) << " start!!! " << a11 << endl;
#endif
		for (iter2 = b.begin(); iter2 != b.end(); ++iter2) {
			b11 = *iter2;
			c11 = a11 & b11;
#ifdef DEBUG
			cout << bitset<10>(c11) << endl;
#endif
			{
				int pp = 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2;
				if (ans % 2 == 1 && c11 % 2 == 1) c11 -= 1;
				while (pp != 1) {
					if ((ans >= pp) && ((ans & pp) != 0) && (c11 >= pp) && ((c11 & pp) != 0)) c11 -= pp;
					pp /= 2;
				}
			}
#ifdef DEBUG
			cout << bitset<10>(b11) << " " << bitset<10>(c11) << " " << b11 << " " << c11 << endl;
#endif
			min_v = min(min_v, c11);
#ifdef DEBUG
			if (min_v == c11) cout << "변동!";
			cout << endl;
#endif
		}
		ans = ans | min_v;
#ifdef DEBUG
		cout << "최종결과" << endl;
		cout << bitset<10>(min_v) << " " << bitset<10>(ans) << endl;
#endif
	}


	cout << ans;

	return 0;
}