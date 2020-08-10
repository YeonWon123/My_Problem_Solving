#include <iostream>
#include <istream>
#include <cstring>
#include <string>
using namespace std;

char a[200];

int main(void)
{
	int N;
	cin >> N;
	cin.ignore();

	while (N--) {
		cin.getline(a, 200);
		int i = 0;
		for (i = 0; (int)a[i] != 32; i++);
		cout << "god";
		for (; i < strlen(a); i++) {
			if ((int)a[i] == 32) continue;
			else cout << a[i];
		}
		cout << "\n";
	}
}