#include <iostream>
using namespace std;

long long rec(long long N, long long K) {
	if (N == K || K == 0)
		return 1;

	return rec(N - 1, K - 1) + rec(N - 1, K);
}

int main(void)
{
	int N, K;
	cin >> N >> K;

	cout << rec(N, K);
	return 0;
}