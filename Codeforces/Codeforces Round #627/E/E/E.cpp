#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int a[2001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, h, l, r;
	cin >> n >> h >> l >> r;
	int start = 0;
	int end = 0;
	int sw = 0;
	int sw2 = 0;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		sw = 0;
		sw2 = 0;
		cin >> a[i];

		start += a[i] - 1;
		if (start >= h) {
			start -= h;
		}

		end += a[i];
		if (end >= h) {
			end -= h;
		}
		
		if (start > end) {
			sw2 = 1;
			end += h;
		}
		else if (start == end) {
			start = l;
			end = r;
			sw++;
		}

		if (start <= l && end >= l) {
			start = l;
			sw++;
		}

		if (start <= r && end >= r) {
			end = r;
			sw++;
		}

		if (sw != 0) {
			answer++;
		}
		else if (sw2 != 0) {
			end -= h;
		}

	//	cout << "start : " << start << ", end : " << end << endl;
	}

	cout << answer;
	return 0;
}