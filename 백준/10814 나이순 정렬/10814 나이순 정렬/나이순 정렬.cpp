#include <iostream>
#include <algorithm>
using namespace std;

typedef struct POINT {
//	int index;
	int age;
	string str;
} point;


bool compare(point a, point b) {
//	if (a.age != b.age)
		return a.age < b.age;
//	return a.index < b.index;
}


point arr[100000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].age >> arr[i].str;
//		arr[i].index = i;
	}

	// 순서를 유지하는 조건 : 구조체에 index 변수를 추가하거나, stable_sort를 사용한다.
	// stable_sort의 경우 더 빠른데 메모리를 많이 먹는다. 
	stable_sort(arr, arr + N, compare);
	for (int i = 0; i < N; i++) {
		cout << arr[i].age << " " << arr[i].str << "\n";
	}

	return 0;
}