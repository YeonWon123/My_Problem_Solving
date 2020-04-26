#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int T;
	cin >> T;

	int A, B;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		cout << A + B << "\n";
	}
}