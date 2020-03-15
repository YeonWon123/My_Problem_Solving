#include <iostream>
using namespace std;

char s;
int a = 0;
int b = 0;

int main(void) {
	for (int i = 0; i < 3; i++) {
		cin >> s;
		if (s == 'A') a++;
		else if (s == 'B') b++;
	}

	if (a != 0 && b != 0)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}