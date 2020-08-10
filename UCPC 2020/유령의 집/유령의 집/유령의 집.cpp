#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;

map<int, char> Y[300001];
map<int, char> X[300001];
map<pair<char, int>, int> res;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M, K, Q, a, b;
	char ch;
	string str;
	cin >> N >> M >> K >> Q;

	for (int i = 0; i < K; i++) {
		cin >> a >> b >> ch;
		Y[a].insert(make_pair(b, ch));
		X[b].insert(make_pair(a, ch));
	}

	map<int, char>::iterator iter;
	map<int, char>::reverse_iterator reverse_iter;
	pair<char, int> save;
	int counts = 0; int dist = 0; int n_dist = 0;
	char n_ch; int n_pos;

	for (int i = 0; i < Q; i++) {
		counts = 0;
		dist = 0;
		n_dist = 0;

		cin >> ch >> a;
		save.first = ch;
		save.second = a;

		// D2 : X[2].end()부터 거꾸로 탐색
		if (ch == 'D') {
			for (reverse_iter = X[a].rbegin()--; reverse_iter != X[a].rend(); reverse_iter++) {
				n_ch = reverse_iter->first;
				n_pos = reverse_iter->second;
			}
		}
		// U2 = X[2].begin()부터 똑바로 탐색
		else if (ch == 'U') {
			for (iter = X[a].begin(); iter != X[a].end(); iter++) {
				n_ch = iter->first;
				n_pos = iter->second;
				if (n_ch == '/') {

				}
				else if (n_ch == '\\') {

				}
				else if (n_ch == '!') {
					counts++;
					n_dist += abs();
					dist += n_dist;
				}
			}
		}
		// L2 = Y[2].begin()부터 똑바로 탐색
		else if (ch == 'L') {
			for (iter = Y[a].begin(); iter != Y[a].end(); iter++) {
				n_ch = iter->first;
				n_pos = iter->second;
			}
		}
		// R2 = Y[2].end()부터 거꾸로 탐색
		else if (ch == 'R') {
			for (reverse_iter = Y[a].rbegin(); reverse_iter != Y[a].rend(); reverse_iter++) {
				n_ch = reverse_iter->first;
				n_pos = reverse_iter->second;
			}
		}

		cout << counts << " " << dist << "\n";
	}

	return 0;
}