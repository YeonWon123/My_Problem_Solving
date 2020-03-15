#include <iostream>
#include <vector>
using namespace std;

int tree[200001] = { -1 };
vector<pair<int, int>> pos;
int main(void)
{
	pos.reserve(200000);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;

	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		tree[b] = a;
	}
	

	// root로 올라가는 것도 있지만
	// 옆으로 넘어가는 것도 있음
	// 트리의 지름에 대해서 알아야 함
	for (int i = N; i > 0; i--) {
		int j;
		int temp = N;
		for (j = 0; j < 3; j++) {
			temp = tree[N];
		}
	}
	
	return 0;
}