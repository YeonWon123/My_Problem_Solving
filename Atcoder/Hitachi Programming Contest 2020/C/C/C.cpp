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
	

	// root�� �ö󰡴� �͵� ������
	// ������ �Ѿ�� �͵� ����
	// Ʈ���� ������ ���ؼ� �˾ƾ� ��
	for (int i = N; i > 0; i--) {
		int j;
		int temp = N;
		for (j = 0; j < 3; j++) {
			temp = tree[N];
		}
	}
	
	return 0;
}