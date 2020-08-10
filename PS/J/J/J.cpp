#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// W = S^2 / (S^2 + A^2)

int n_plus[1001];
int n_minus[1001];
double score[1001];

int main(void)
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n, m;
		cin >> n >> m;
		int a, b, p, q;
		memset(n_plus, 0, sizeof(n_plus));
		memset(n_minus, 0, sizeof(n_minus));
		for (int j = 0; j < m; j++) {
			cin >> a >> b >> p >> q;
			n_plus[a] += p;
			n_minus[a] += q;
			n_plus[b] += q;
			n_minus[b] += p;
		}

		for (int j = 0; j < n; j++) {
			int temp1 = n_plus[j] * n_plus[j];
			int temp2 = n_minus[j] * n_minus[j];
			cout << "Ãâ·Â: " << temp1 << " " << temp2 << "\n";
			if (temp1 == 0 || temp2 == 0) score[j] = 0;
			else score[j] = (double)temp1 / (temp1 + temp2) * 1000;
		}

		sort(score, score + n);

		for (int j = 0; j < n; j++) {
			cout << "score : " << score[j] << "\n";
		}
		cout << score[n - 1] << "\n" << score[0] << "\n";
	}
}