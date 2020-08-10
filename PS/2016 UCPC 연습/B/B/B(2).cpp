#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int n;
struct Node {
	int val, open, num;
	Node(int v = 0, int o = 0, int n = 0) :val(v), open(o), num(n) {}
	bool operator < (const Node& o) const {
		if (val == o.val)
			return open < o.open;
		return val < o.val;
	}
};
int d[300001];
bool check[300001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<Node> p;
	for (int i = 1, s = 0, e = 0; i < n + 1; i++) {
		cin >> s >> e;
		p.push_back(Node(s, 1, i));
		p.push_back(Node(e, 2, i));
	}
	sort(p.begin(), p.end());

	int cnt = 0;
	for (Node node : p) {
		if (node.open == 1) {
			d[node.num] = cnt;
			cnt++;
		}
		else if (node.open == 2) {
			cnt--;
		}
	}
	int maxi = -1;
	int num = 0;
	for (int i = 1; i < n + 1; i++) {
		if (maxi < d[i]) {
			maxi = d[i];
			num = i;
		}
	}
	for (Node node : p) {
		if (node.open == 1) {
			if (node.num == num) {
				cout << d[node.num] + 1 << '\n';
				for (int i = 1; i < n + 1; i++) {
					if (check[i]) cout << i << ' ';
				}
				cout << node.num;
				break;
			}
			check[node.num] = true;
		}
		else if (node.open == 2) {
			check[node.num] = false;
		}
	}
}
