#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

// arr[i] : i�� ������ 1, ������ 0
int arr[21] = { 0, };


// add x : S�� x�� �߰��Ѵ�. (1 �� x �� 20) S�� x�� �̹� �ִ� ��쿡�� ������ �����Ѵ�.
void add(int x) {
	arr[x] = 1;
}

// remove x : S���� x�� �����Ѵ�. (1 �� x �� 20) S�� x�� ���� ��쿡�� ������ �����Ѵ�.
void remove(int x) {
	arr[x] = 0;
}

// check x : S�� x�� ������ 1��, ������ 0�� ����Ѵ�. (1 �� x �� 20)
void check(int x) {
	if (arr[x] == 1) cout << "1\n";
	else			 cout << "0\n";
}

// toggle x : S�� x�� ������ x�� �����ϰ�, ������ x�� �߰��Ѵ�. (1 �� x �� 20)
void toggle(int x) {
	if (arr[x] == 1)
		arr[x] = 0;
	else
		arr[x] = 1;
}

// all: S��{ 1, 2, ..., 20 } ���� �ٲ۴�.
void all() {
	for (int j = 1; j <= 20; j++) {
		arr[j] = 1;
	}
}

// empty: S�� ���������� �ٲ۴�. 
void empty() {
	memset(arr, 0, sizeof(arr));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		string str;
		int x;
		cin >> str;
		if (str == "add") {
			cin >> x;
			add(x);
		}
		else if (str == "check") {
			cin >> x;
			check(x);
		}
		else if (str == "remove") {
			cin >> x;
			remove(x);
		}
		else if (str == "toggle") {
			cin >> x;
			toggle(x);
		}
		else if (str == "all") {
			all();
		}
		else { // str == empty
			empty();
		}
	}

	return 0;
}