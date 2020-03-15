#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	if (sqrt(a) - sqrt(c) + sqrt(b) < 0) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}