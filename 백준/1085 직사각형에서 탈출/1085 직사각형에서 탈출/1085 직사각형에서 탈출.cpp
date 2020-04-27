#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	// x, y, (w-x), (h-y)를 비교해서
	// 제일 작은 값이 정답이 된다.
	int min_value = min(x, min(y, min(w - x, h - y)));
	cout << min_value;
}