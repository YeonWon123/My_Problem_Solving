#include <iostream>
using namespace std;

int main(void) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (i == 0 && i != '-') cout << str[i];
		else if (i == 0) continue;
		else if (str[i - 1] == '-') cout << str[i];
	}

}