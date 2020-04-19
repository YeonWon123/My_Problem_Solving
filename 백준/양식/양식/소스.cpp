#include <iostream>
#include <string>
#define PROBLEM_NUM_MAX 10 // 최대 문제 수
using namespace std;

// 1번 문제의 정답은 answer[0]에, 2번 문제의 정답은 answer[1]에, ... 기입한다.
string answer[PROBLEM_NUM_MAX] = { "", "", "", "", "", "", "", "", "", "" };

int main(void) {
	int a; cin >> a;	// 의미 없는 부분이다.

	// 한줄에 하나씩 정답을 출력한다.
	for (int i = 0; i < PROBLEM_NUM_MAX; i++) {
		cout << answer[i] << endl;
	}
	
	return 0;
}


