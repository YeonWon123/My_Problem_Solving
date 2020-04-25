#include <iostream>
using namespace std;

int arr[9];
int max_n = -1;
int index = -1;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		if (max_n < arr[i]) {
			max_n = arr[i];
			index = i+1;
		}
	}

	cout << max_n << "\n" << index;
	return 0;
}