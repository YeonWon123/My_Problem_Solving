#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long N, A, B;
long long answer = 0;
long long total = 0;
long long total_div = 0;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> A >> B;

	if (A != 0) {
		if (B == 0) {
			cout << N;
			return 0;
		}

		total = N / (A + B);
		total_div = N % (A + B);

		answer = total * A;
		if (total_div >= A) {
			answer += A;
		}
		else
			answer += total_div;
	}
	else {
		cout << 0;
		return 0;
	}

	cout << answer;
	return 0;
}