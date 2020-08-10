#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

stack<char> st;

char s[200001];
int index[200001];
char counts_end[200001];


int main(void)
{
	int t, n, counts, max_counts, sw;
	cin >> t;
	while (t--) {
		cin >> n;
		memset(counts_end, ' ', sizeof(counts_end));
		counts = 1;
		max_counts = 1;

		int temp = 1;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			if (i != 0 && s[i] == s[i - 1]) {
				temp++;
				max_counts = max(temp, max_counts);
			}
			else {
				temp = 1;
			}
		}
		
		cout << max_counts << "\n";
		
		sw = 0;
		char save = ' ';

		for (int i = 0; i < n; i++) {
			if (i == 0) {
				index[i] = 1;
				counts_end[counts] = s[i];
			}
			else if (s[i] == s[i - 1]) {
				if (save == ' ') {
					save = s[i];
					counts++;
					index[i] = counts;
					counts_end[counts] = s[i];
				}
				else if (save == s[i]) {
					if (sw == 0) {
						if (counts < max_counts)
							counts++;
						while(counts_end[counts] == s[i] && counts < max_counts)
							counts++;
						while (counts_end[counts] == s[i] && counts > 1) {
							sw = 1;
							counts--;
						}
					}
					else if (counts == 1) {
						sw = 0;
						if (counts < max_counts)
							counts++;
						while (counts_end[counts] == s[i] && counts < max_counts)
							counts++;
						while (counts_end[counts] == s[i] && counts > 1) {
							sw = 1;
							counts--;
						}
					}
					else { // sw == 1
						if (counts > 1)
							counts--;
						while (counts_end[counts] == s[i] && counts > 1)
							counts--;
						while (counts_end[counts] == s[i] && counts < max_counts) {
							sw = 0;
							counts++;
						}
					}
					index[i] = counts;
					counts_end[counts] = s[i];
				}
				else { // save != s[i]
					save = s[i];
					if (counts > 1)
						counts--;
					while (counts_end[counts] == s[i] && counts > 1)
						counts--;

					while (counts_end[counts] == s[i] && counts < max_counts) {
						sw = 0;
						counts++;
					}

					index[i] = counts;
					counts_end[counts] = s[i];

					if (sw == 0) sw = 1;
					else sw = 0;
				}
			}
			else {
				index[i] = counts;
				counts_end[counts] = s[i];
			}
		}

		for (int i = 0; i < n; i++) {
			cout << index[i] << " ";
		}
		cout << "\n";
	}
}