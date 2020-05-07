// 다시 해보기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[31];

int main(void)
{
	arr[1] = 1;
	int a = 0;
	int i = 1;
	while (true) {
		a = pow(2, i);
		if (a < 0) break;
	//	cout << i << " " << a << endl;
		arr[i+1] = a;
		i++;
	}
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, d, j;
	cin >> t;

	for (i = 0; i < t; i++) {
		cin >> d;
		for (j = 1; arr[j] < d; j++) {
			d = d - arr[j];
		}
		cout << j << "\n";


		for (int p = 1; p <= j; p++) {
			if (d != 0 && arr[p + 1] >= d && d >= arr[p]) {
				cout << d - arr[p] << " " << arr[p+1] - d << " ";
			}
			else
				cout << arr[p + 1] - arr[p] << " ";
		}
		cout << "\n";
	}
	return 0;
}