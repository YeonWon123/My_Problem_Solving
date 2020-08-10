#include <iostream>
#include <algorithm>
using namespace std;


// 1 2 3 4 5 6 7 8 9 
// 1   3   5   7   9
// 1     4     7    
// 1       5        
// 1         6      

// n / 1
// (n-1) / 2 + 1
// (n-1) / 3 + 1

// n + (n-1) / 1 + (n-1) / 2 + (n-1) / 3 + ... + (n-1) / (n-1)
// 9 + (8 / 1 + 8 / 2 + 8 / 3 + 8 / 4) + (1 + 1 + 1 + 1)
// n + (n-1) * (1/1 + 1/2 + 1/3 + 1/4 + ... + 1/(n-1))
// n + (n - 1) + (n - 1) / 2 + (n - 1) / 4 + ...

// 9 + 8 + 4 + 2 + 1 + 1 + 1 + 1 + ...

int main(void)
{
	long long n;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	

	/*
	1
	1 1
	1 1 1 1 
	1 1 1 1 1 1 1 1
	...
	
	*/
	long long a = 0;
	for (long long i = n + 1; i != 0; i = n / ((n / i) + 1))
		a += (n / i + 1) * (i - (n / ((n / i) + 1)));
	cout << a;

	/*
	// 시간초과 나는 코드
	for (int i = 2; i < n; i++) {
		a += (n - 1) / i;
	}

	cout << a;
	*/
}
