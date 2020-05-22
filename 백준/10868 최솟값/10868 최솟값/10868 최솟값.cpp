#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1000001];
long long segment[4000001];

// ���׸�Ʈ Ʈ�� ���� - �ּڰ� Ʈ��
// ���� : ��� ��ȣ(segment), ���� ��ȣ(arr), �� ��ȣ(arr)
long long seg_init(int node, int start, int end) {
	if (start == end) {
		return segment[node] = arr[start];
	}

	int mid = (start + end) / 2;
	return segment[node] = min(seg_init(node * 2, start, mid), seg_init(node * 2 + 1, mid + 1, end));
}

// ���׸�Ʈ Ʈ�� ������Ʈ
// ���� : ��� ��ȣ(segment), ���� ��ȣ(arr), �� ��ȣ(arr), �ٲٰ��� �ϴ� ��� ��ȣ(arr), ����(diff)
// ����(diff)�� ��� �ٲٱ� ���� ���� �ٲ� ���� ���̸� ��Ÿ����.
void seg_update(int node, int start, int end, int index, long long new_value) {
	// ���� ��ȣ�� �� ��ȣ ���̿� �ٲٰ��� �ϴ� ��尡 ������ �Լ� ����
	if (!(start <= index && index <= end)) return;

	// ��ü ���� �ּڰ��� ���Ž�Ŵ
	segment[node] = min(segment[node], new_value);

	// �ٲپ�� �ϴ� ���� ���� ��� diff�� ����
	if (start != end) {
		int mid = (start + end) / 2;
		seg_update(node * 2, start, mid, index, new_value);
		seg_update(node * 2 + 1, mid + 1, end, index, new_value);
	}

}

// ���׸�Ʈ Ʈ�� �ּڰ� ���ϱ�
// ���� :	��� ��ȣ(segment), ���� ��ȣ(arr), �� ��ȣ(arr), 
//			���Ϸ��� �κ��� ���� ����(segment), ���Ϸ��� �κ��� ������ ����(segment)
long long seg_min(int node, int start, int end, int left, int right) {
	// 1.	���� ������ ���Ϸ��� ���׸�Ʈ Ʈ���� ������ ��ġ�� �ʴ� ��� -> 1000000001�� ����
	if (left > end || right < start) {
		return 1000000001;
	}

	// 2.	���� ������ ���Ϸ��� ���׸�Ʈ Ʈ���� ������ ������ ���ԵǴ� ��� -> segment[node]�� ����
	//		���� ���� <= ���Ϸ��� �κ� ���� ���׸�Ʈ Ʈ�� ����
	if (left <= start && end <= right) {
		return segment[node];
	}

	// 3.	���� ������ ���Ϸ��� ���׸�Ʈ Ʈ���� �������� ũ�ų�, �Ϻκи� ��ġ�� ���
	//		�� ���� �ѷ� ����� Ž���� �����Ѵ�.
	int mid = (start + end) / 2;
	return min(seg_min(node * 2, start, mid, left, right), seg_min(node * 2 + 1, mid + 1, end, left, right));
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// ���׸�Ʈ Ʈ���� ������
	seg_init(1, 0, N - 1);

	int a, b;

	// a ~ b ������ �ּڰ��� ������
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << seg_min(1, 0, N - 1, a - 1, b - 1) << "\n";
	}
	return 0;
}