#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

// arr[i] : i가 있으면 1, 없으면 0
int arr[21] = { 0, };


// add x : S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
void add(int x) {
	arr[x] = 1;
}

// remove x : S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
void remove(int x) {
	arr[x] = 0;
}

// check x : S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
void check(int x) {
	if (arr[x] == 1) cout << "1\n";
	else			 cout << "0\n";
}

// toggle x : S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
void toggle(int x) {
	if (arr[x] == 1)
		arr[x] = 0;
	else
		arr[x] = 1;
}

// all: S를{ 1, 2, ..., 20 } 으로 바꾼다.
void all() {
	for (int j = 1; j <= 20; j++) {
		arr[j] = 1;
	}
}

// empty: S를 공집합으로 바꾼다. 
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