#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

struct point {
	int x;
	int y;
};

point graph[100000];
int counts[100001] = { 0 };
vector<int> save;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, a, b;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		graph[i].x = a; graph[i].y = b;
		counts[a]++;
		counts[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (counts[i] == 1) {
			save.push_back(i);
		}
	}

	int up = 0;
	int down = n - 2;
	int sw = 0;
	for (int i = 0; i < n - 1; i++) {
		sw = 0;
		for (int j = 0; j < save.size(); j++) {
			if (save[j] == graph[i].x || save[j] == graph[i].y) {
				cout << up << "\n";
				up++;
				sw = 1;
				break;
			}
		}

		if (sw == 0) {
			cout << down << "\n";
			down--;
		}
	}

	return 0;
}