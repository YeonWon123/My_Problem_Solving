#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	// x, y, (w-x), (h-y)�� ���ؼ�
	// ���� ���� ���� ������ �ȴ�.
	int min_value = min(x, min(y, min(w - x, h - y)));
	cout << min_value;
}