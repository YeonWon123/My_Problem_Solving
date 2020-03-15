// time over
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

string S, temp;
int Q;
bool reversed = false;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> S >> Q;
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
					S = temp + S;
				}
				else {
					// add end
					cin >> temp;
					S = S + temp;
				}
			}
			else {
				if (!reversed) {
					// add end
					cin >> temp;
					S = S + temp;
				}
				else {
					// add front
					cin >> temp;
					S = temp + S;
				}
			}
		}
	}

	if (reversed) {
		for (int i = S.size() - 1; i > -1; i--)
			cout << S[i];
	}
	else {
		cout << S;
	}

	return 0;
}