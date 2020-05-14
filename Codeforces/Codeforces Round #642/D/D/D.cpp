#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int a[200001];

typedef struct POINT {
	int first;
	int second;
} point;

bool operator <(point a, point b) {
	if (a.second - a.first != b.second - b.first)
		return ((a.second - a.first) < (b.second - b.first));
	else
		return (a.first > b.first);
}

priority_queue<point> q;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	int n;
	for (int i = 0; i < t; i++) {
		memset(a, 0, sizeof(a));
		cin >> n;

		int l = 1, r = n;
		q.push({ l, r });
		for (int j = 1; j <= n; j++) {
			l = q.top().first;
			r = q.top().second;
			q.pop();

			if ((r - l + 1) % 2 != 0) {
				a[(r + l) / 2] = j;
				if (r == l) continue;

				int mid = (r + l) / 2;
				if (l <= mid - 1)
					q.push( { l, mid - 1 } );
				if (mid + 1 <= r)
					q.push( {mid + 1, r} );

			}
			else {
				a[(r + l - 1) / 2] = j;
				if (r == l) continue;

				int mid = (r + l - 1) / 2;
				if (mid + 1 <= r) 
					q.push({ mid + 1, r });
				if (l <= mid - 1)
					q.push({ l, mid - 1 });
			}
		}
		
		for (int j = 1; j <= n; j++) {
			cout << a[j] << " ";
		}
		cout << "\n";
	}

	return 0;
}