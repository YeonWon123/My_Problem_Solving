#include <iostream>
#include <algorithm>
using namespace std;

struct three {
	int a_pos;
	int b_pos;
	int discount;
};

int a[100000];
int b[100000];
three m[100000];

int a_min = 99999999;
int b_min = 99999999;
int total_min = 99999999;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int A, B, M;
	cin >> A >> B >> M;
	for (int i = 0; i < A; i++) {
		cin >> a[i];
		a_min = min(a_min, a[i]);
	}

	for (int i = 0; i < B; i++) {
		cin >> b[i];
		b_min = min(b_min, b[i]);
	}
	
	total_min = a_min + b_min;

	int temp;
	for (int i = 0; i < M; i++) {
		cin >> m[i].a_pos >> m[i].b_pos >> m[i].discount;
		temp = a[m[i].a_pos - 1] + b[m[i].b_pos - 1] - m[i].discount;
		total_min = min(total_min, temp);
	}

	cout << total_min;
	return 0;
}