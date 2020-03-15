#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<char> fronts, backs;
char temp;
string S;
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
			if (reversed == true)
				reversed = false;
			else
				reversed = true;
		}
		else {
			cin >> F;
			if (F == 1) {
				if (reversed == false) {
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
				if (reversed == false) {
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

	if (reversed == true) {
		for (int i = backs.size() - 1; i > -1; i--)
			cout << backs[i];

		for (int i = S.size() - 1; i > -1; i--)
			cout << S[i];

		for (int i = 0; i < fronts.size(); i++)
			cout << fronts[i];
	}
	else {
		for (int i = fronts.size() - 1; i > -1; i--)
			cout << fronts[i];

		for (int i = 0; i < S.size(); i++) {
			cout << S[i];
		}

		for (int i = 0; i < backs.size(); i++)
			cout << backs[i];
	}

	return 0;
}