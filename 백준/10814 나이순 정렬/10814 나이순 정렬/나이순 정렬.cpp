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

	// ������ �����ϴ� ���� : ����ü�� index ������ �߰��ϰų�, stable_sort�� ����Ѵ�.
	// stable_sort�� ��� �� ������ �޸𸮸� ���� �Դ´�. 
	stable_sort(arr, arr + N, compare);
	for (int i = 0; i < N; i++) {
		cout << arr[i].age << " " << arr[i].str << "\n";
	}

	return 0;
}