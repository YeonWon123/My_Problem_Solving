#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//int arr[31];

void solve() {
	vector<int>inc;
	int N;
	cin >> N;
	//construct sequence 1, 2, 4, ... while sum <= N
	for (int i = 1; i <= N; i *= 2) {
		inc.push_back(i);
		N -= i;
	}
	//if sum is not N, we insert and sort
	if (N > 0) {
		inc.push_back(N);
		sort(inc.begin(), inc.end());
	}
	cout << inc.size() - 1 << endl;
	for (int i = 1; i < (int)inc.size(); i++)
		cout << inc[i] - inc[i - 1] << ' ';
	cout << endl;
}

int main() {
	int t; cin >> t;
	while (t--)
		solve();
}

/*
int main(void)
{

	int a = 1;
	int i = 1;
	while (true) {
		a += pow(2, i);
		if (a < 0) break;
	//	cout << i << " " << a << endl;
		arr[i] = a;
		i++;
	}

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, d, j;
	cin >> t;

	for (i = 0; i < t; i++) {
		cin >> d;
		for (j = 1; arr[j] < d; j++);
		cout << j << "\n";
	}
	return 0;
}
*/