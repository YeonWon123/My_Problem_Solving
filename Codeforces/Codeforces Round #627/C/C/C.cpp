#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

string s;
int total_counts = 0;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	int counts = 0;
	cin >> t;
	s.reserve(210000);
	int sw = 0; // Ω√¿€Ω√ 0, L : 1, R : 2
	for (int i = 0; i < t; i++) {
		sw = 0;
		total_counts = 0;
		counts = 0;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'L') {
				if (sw == 0 || sw == 2) {
					sw = 1;
					counts = 1;
				}
				else {
					counts++;
				}
			}
			else {
				if (sw == 1) {
					sw = 2;
					total_counts = max(total_counts, counts);
				}
			}
		}

		total_counts = max(total_counts, counts);
		cout << total_counts + 1 << "\n";
	}

	return 0;
}