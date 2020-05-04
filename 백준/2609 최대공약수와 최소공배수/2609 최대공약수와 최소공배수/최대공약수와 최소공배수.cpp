#include <iostream>
#include <numeric>
using namespace std;

// 최대공약수
// 유클리드 호제법 이용
int gcd(int a, int b) {
	if (a < b)
		swap(a, b);

	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

// 최소공배수
// 앞에서 구한 최대공약수를 이용
// 나눗셈을 먼저 하여 오버플로우 방지
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int main(void)
{
	int a, b;
	cin >> a >> b;

	// cout << gcd(a, b) << "\n" << lcm(a, b);
	return 0;
}