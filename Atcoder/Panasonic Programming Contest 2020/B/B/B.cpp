#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long H, W;
	cin >> H >> W;

	long long answer = 0;
	if (W % 2 != 0 && H % 2 != 0) {
		answer = W * H / 2 + 1;
	}
	else {
		answer = W * H / 2;
	}

	cout << answer;
	return 0;
}