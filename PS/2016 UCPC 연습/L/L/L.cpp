#include <iostream>
using namespace std;

int main(void)
{
	int N, K, P, W;
	cin >> N >> K >> P >> W;
	if (P % W == 0) cout << P / W;
	else cout << P / W + 1;
}