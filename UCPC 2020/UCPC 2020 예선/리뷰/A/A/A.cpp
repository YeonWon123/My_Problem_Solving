#include <iostream>
using namespace std;

int main(void)
{
	int a, b, c, d, e, f, x, y;
	cin >> a >> b >> c >> d >> e >> f;

	x = (e * c - b * f) / (a * e - b * d);
	y = (a * f - c * d) / (a * e - b * d);

	cout << x << " " << y;
}