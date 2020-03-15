#define DEBUG

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

long long answer = 0;

// 1로만 이루어진 곳의 가로 길이
vector<int> a;

// 1로만 이루어진 곳의 세로 길이
vector<int> b;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	int temp;
	int last_zero = 0;
	for (int j = 1; j <= n; j++) {
		cin >> temp;
		if (temp == 0) {
			if (j - last_zero >= 1) {
				a.push_back(j - 1 - last_zero);
			}
			last_zero = j;
		}
	}

	if (last_zero != n) {
		a.push_back(n - last_zero);
	}

	last_zero = 0;
	for (int j = 1; j <= m; j++) {
		cin >> temp;
		if (temp == 0) {
			if (j - last_zero >= 1) {
				cout << "j : " << j << ", last_zero : " << last_zero << endl;
				b.push_back(j - 1 - last_zero);
			}
			last_zero = j;
		}
	}

	if (last_zero != m) {
		b.push_back(m - last_zero);
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<pair<int, int>> aa;
	vector<pair<int, int>> bb;

	int lasts;
	int a_last_counts = 0;
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
		if (i == 0) {
			aa.push_back(make_pair(a[i], 1));
			lasts = a[i];
			continue;
		}
		else if (lasts == a[i]) {
			aa[a_last_counts].second++;
		}
		else {
			aa.push_back(make_pair(a[i], 1));
			lasts = a[i];
			a_last_counts++;
		}
	}
	a_last_counts++;
	cout << "\n";

	int b_last_counts = 0;
	for (int i = 0; i < b.size(); i++) {
		cout << b[i] << " ";
		if (i == 0) {
			bb.push_back(make_pair(b[i], 1));
			lasts = b[i];
			continue;
		}
		else if (lasts == b[i]) {
			bb[b_last_counts].second++;
		}
		else {
			bb.push_back(make_pair(b[i], 1));
			lasts = b[i];
			b_last_counts++;
		}
	}
	b_last_counts++;
	cout << "\n";
#ifdef DEBUG
	
	for (int j = 0; j < a_last_counts; j++) {
		cout << "원소는 : " << aa[j].first << ", 원소의 개수는 : " << aa[j].second << endl;
	}
	cout << endl;

	for (int j = 0; j < b_last_counts; j++) {
		cout << "원소는 : " << bb[j].first << ", 원소의 개수는 : " << bb[j].second << endl;
	}
		
#endif
	int aaa, bbb, temp2;
	for (int i = 0; i < a_last_counts; i++) {
		for (int j = 0; j < b_last_counts; j++) {
			aaa = min(aa[i].first, bb[j].first);
			bbb = max(aa[i].first, bb[j].first);
		//	int kdiv2 = k / 2;
		//	if (k == 1) kdiv2 = 1;

		//	cout << "aaa : " << aaa << ", bbb : " << bbb << endl;
		//	cout << "kdiv2 : " << kdiv2 << endl;

			for (int p = 1; p <= k && p <= aaa; p++) {
				if (k % p == 0) {
					temp2 = k / p;
					if (temp2 > bbb) {
#ifdef DEBUG
						cout << "나가기! temp2 : " << temp2 << ", " << "bbb : " << bbb << endl;
#endif
					}
					else {
						answer += (long long)(aaa - p + 1) * (bbb - temp2 + 1) * aa[j].second * bb[j].second;
#ifdef DEBUG
						cout << "정답추가! answer : " << answer << endl;
#endif
					}
				}
			}
		}
	}

	cout << answer;
	return 0;
}