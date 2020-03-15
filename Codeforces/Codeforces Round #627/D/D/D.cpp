#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
//#include <cstdio>
using namespace std;

int a[200000];
int b[200000];
int c[200000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
		c[i] = a[i] - b[i];
	}

	int counts = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c[i] + c[j] > 0 && i < j) {
				counts++;
			}
		}
	}

	cout << counts << endl;
	/*
	counts = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] + a[j] > b[i] + b[j] && i < j) {
				counts++;
				printf("(a[%d] + a[%d] > b[%d] + b[%d]) : (%d + %d) > (%d + %d)\n", i, j, i, j, a[i], a[j], b[i], b[j]);
			}
		}
	}
	cout << "ÃÑ °³¼ö : " << counts << endl;
	*/
	return 0;
}