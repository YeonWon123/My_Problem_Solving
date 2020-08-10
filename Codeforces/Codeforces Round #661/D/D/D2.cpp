#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

stack<char> st;

char s[200001];
char counts_end[200001];
int index[200001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t, n, counts, max_counts, sw, max_counts_black, max_counts_white;
	cin >> t;
	while (t--) {
		cin >> n;
		memset(counts_end, ' ', sizeof(counts_end));
		counts = 1;
		max_counts = 1;
		max_counts_white = 1;
		max_counts_black = 1;

		for (int i = 0; i < n; i++) {
			cin >> s[i];
			if (i == 0) continue;

			if (s[i] == s[i - 1]) {
				if (s[i] == '0') max_counts_white++;
				else max_counts_black++;
			}
		}
		max_counts = max(max_counts_black, max_counts_white);

		counts = 1;
		counts_end[1] = s[0];
		index[0] = counts;
		sw = 0;

		for (int i = 1; i < n; i++) {
			sw = 0;
			if (s[i] != s[i - 1]) {
				counts_end[counts] = s[i];
			}
			else {
				for (int j = counts; j <= max_counts; j++) {
					if (counts_end[j] != s[i]) {
						counts = j;
						counts_end[counts] = s[i];
						sw = 1;
						break;
					}
				}
				if (sw == 0) {
					for (int j = counts - 1; j > 0; j--) {
						if (counts_end[j] != s[i]) {
							counts = j;
							counts_end[counts] = s[i];
							break;
						}
					}
				}
			}
			index[i] = counts;
		}

		cout << max_counts << "\n";
		for (int i = 0; i < n; i++) {
			cout << index[i] << " ";
		}
		cout << "\n";
	}
}