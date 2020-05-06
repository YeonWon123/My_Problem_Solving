#include <iostream>
#include <deque>
using namespace std;

deque<int> arr;

int main(void)
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		arr.push_back(i);
	}

	int temp;
	while (arr.size() != 1) {
		arr.pop_front();
		temp = arr.front();
		arr.pop_front();
		arr.push_back(temp);
	}
	cout << arr.front();
	return 0;
}