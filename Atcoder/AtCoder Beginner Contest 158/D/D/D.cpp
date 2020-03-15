#include <iostream>
#include <deque>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

char temp;
char S[100001];
char answer[300002];
int Q;
deque<char> fronts, backs;
bool reversed = false;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> S >> Q;
	int s_size = strlen(S);
	int T, F;
	for (int i = 0; i < Q; i++) {
		cin >> T;
		if (T == 1) {
			// reverse
			reversed = !reversed;
		}
		else {
			cin >> F;
			if (F == 1) {
				if (!reversed) {
					// add front
					cin >> temp;
					fronts.push_back(temp);
				}
				else {
					// add end
					cin >> temp;
					backs.push_back(temp);
				}
			}
			else {
				if (!reversed) {
					// add end
					cin >> temp;
					backs.push_back(temp);
				}
				else {
					// add front
					cin >> temp;
					fronts.push_back(temp);
				}
			}
		}
	}

	// ÀÏ´Ü »«´Ù
	int p = 0;
	while (!fronts.empty()) {
		answer[p] = fronts.top();
		fronts.pop();
		p++;
	}

	answer[p] = '3';
	p++;

	while (!backs.empty()) {
		answer[p] = backs.top();
		backs.pop();
		p++;
	}

	answer[p] = '1';
	p++;

	if (reversed) {
		while (p != -1) {
			p--;
			if (answer[p] == '1')
				continue;

			if (answer[p] == '3')
				break;

			else {
				cout << answer[p];
			}
		}

		for (int i = s_size - 1; i > -1; i--) {
			cout << S[i];
		}

		while (p != -1) {
			p--;
			if (answer[p] == '3')
				break;
			else {
				cout << answer[p];
			}
		}
	}
	else {
		int i;
		for (i = 0; answer[i] != '3' && answer[i] != '1'; i++) {
			cout << answer[i];
		}

		for (int j = 0; j < s_size; j++) {
			cout << S[j];
		}

		for (; answer[i] != '3' && answer[i] != '1' ; i++) {
			cout << answer[i];
		}
	}

	return 0;
}