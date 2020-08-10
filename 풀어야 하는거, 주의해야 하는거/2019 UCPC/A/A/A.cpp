#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	n--;
	int res = n % 8;
	switch (res) {
	case 0:
		cout << 1;
		break;
	case 1:
	case 7:
		cout << 2;
		break;
	case 2:
	case 6:
		cout << 3;
		break;
	case 3:
	case 5:
		cout << 4;
		break;
	case 4:
		cout << 5;
		break;
	default:
		cout << "error";
		break;
	} 
}