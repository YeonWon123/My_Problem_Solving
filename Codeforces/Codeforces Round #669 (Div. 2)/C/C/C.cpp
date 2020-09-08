#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int a[10001];

// 질문을 하고 응답을 받는 부분
// 질문 : "? x y"
// 대답 : k
int query(int x, int y) {
	cout << "? " << x << ' ' << y << "\n";
	cin >> x;
	return x;
}

int main(void)
{
//  이 문제에서는 쓰면 오류가 발생한다.
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	// two pointer 기법과 유사하게 한다.
	// p = 1, i = 2부터 탐색 시작
	// p가 정해지면 -> p = i, i = i + 1
	// i가 정해지면 -> p = p, i = i + 1
	int p = 1;
	for (int i = 2; i <= n; i++) {
		int v1 = query(i, p);
		int v2 = query(p, i);
		
		// 설명 : a % b 보다 b % a가 큰 경우 : b < a이며 a = b % a가 된다.
		// 설명 : a % b 보다 b % a가 작은 경우 : b > a이며 b = b % a가 된다.
		// 설명 : a % b가 b % a와 같은 경우 : 존재할 수 없다. (a != b이기 때문)
		if (v1 < v2) a[p] = v2, p = i;
		else a[i] = v1;
	}
	// 마지막 남은 한자리는 n이 되어야 한다.
	a[p] = n;

	cout << "!";
	for (int i = 1; i <= n; i++) {
		cout << " " << a[i];
	}
	fflush(stdout);

	return 0;
}