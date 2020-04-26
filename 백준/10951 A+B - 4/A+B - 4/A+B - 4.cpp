#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str;

	while (true)
	{
		getline(cin, str);
		if (cin.eof()) break;
		cout << str[0] - '0' + str[2] - '0' << "\n";
	}
	return 0;
}