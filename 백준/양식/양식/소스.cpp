#include <iostream>
#include <string>
#define PROBLEM_NUM_MAX 10 // �ִ� ���� ��
using namespace std;

// 1�� ������ ������ answer[0]��, 2�� ������ ������ answer[1]��, ... �����Ѵ�.
string answer[PROBLEM_NUM_MAX] = { "", "", "", "", "", "", "", "", "", "" };

int main(void) {
	int a; cin >> a;	// �ǹ� ���� �κ��̴�.

	// ���ٿ� �ϳ��� ������ ����Ѵ�.
	for (int i = 0; i < PROBLEM_NUM_MAX; i++) {
		cout << answer[i] << endl;
	}
	
	return 0;
}


