// ���׸�Ʈ Ʈ���� �̿��� ����
#include <iostream>
using namespace std;

long long arr[1000001];
long long segment[4000001];

// ���׸�Ʈ Ʈ�� ����
// ���� : ��� ��ȣ(segment), ���� ��ȣ(arr), �� ��ȣ(arr)
long long seg_init(int node, int start, int end) {
	if (start == end) {
		return segment[node] = arr[start];
	}

	int mid = (start + end) / 2;
	return segment[node] = seg_init(node * 2, start, mid) + seg_init(node * 2 + 1, mid + 1, end);
}

// ���׸�Ʈ Ʈ�� ������Ʈ
// ���� : ��� ��ȣ(segment), ���� ��ȣ(arr), �� ��ȣ(arr), �ٲٰ��� �ϴ� ��� ��ȣ(arr), ����(diff)
// ����(diff)�� ��� �ٲٱ� ���� ���� �ٲ� ���� ���̸� ��Ÿ����.
void seg_update(int node, int start, int end, int index, long long diff) {
	// ���� ��ȣ�� �� ��ȣ ���̿� �ٲٰ��� �ϴ� ��尡 ������ �Լ� ����
	if (!(start <= index && index <= end)) return;

	// ��ü ���� �յ� diff��ŭ ������Ŵ (�̶� diff�� ������ ���� ����)
	segment[node] += diff;

	// �ٲپ�� �ϴ� ���� ���� ��� diff�� ����
	if (start != end) {
		int mid = (start + end) / 2;
		seg_update(node * 2, start, mid, index, diff);
		seg_update(node * 2 + 1, mid + 1, end, index, diff);
	}

}

// ���׸�Ʈ Ʈ�� �� ���ϱ�
// ���� :	��� ��ȣ(segment), ���� ��ȣ(arr), �� ��ȣ(arr), 
//			���Ϸ��� �κ� ���� ���� ����(segment), ���Ϸ��� �κ� ���� ������ ����(segment)
long long seg_sum(int node, int start, int end, int left, int right) {
	// 1.	���� ������ ���Ϸ��� ���׸�Ʈ Ʈ���� ���� ��ġ�� �ʴ� ��� -> 0�� ����
	if (left > end || right < start) {
		return 0;
	}

	// 2.	���� ������ ���Ϸ��� ���׸�Ʈ Ʈ���� �տ� ������ ���ԵǴ� ��� -> segment[node]�� ����
	//		���� ���� <= ���Ϸ��� �κ� �� ���׸�Ʈ Ʈ�� ����
	if (left <= start && end <= right) {
		return segment[node];
	}

	// 3.	���� ������ ���Ϸ��� ���׸�Ʈ Ʈ���� �պ��� ũ�ų�, �Ϻκи� ��ġ�� ���
	//		�� ���� �ѷ� ����� Ž���� �����Ѵ�.
	int mid = (start + end) / 2;
	return seg_sum(node * 2, start, mid, left, right) + seg_sum(node * 2 + 1, mid + 1, end, left, right);
}

int main(void) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	// �Է��� ����
	// �Է¹޴� �迭�� index�� 0���� N-1����
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// ���׸�Ʈ Ʈ���� ����� ����
	// ����Լ��� �����ϴ� ���� ����!
	// ���׸�Ʈ Ʈ���� index�� 1���� ���� (node��ȣ�� 1���� ����)
	seg_init(1, 0, N - 1);

	// �� ��������� �Է��� �����鼭 ������ ��������
	int a, b, c;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		// ����(update)
		if (a == 1) {
			// b��° ���� c�� �ٲ�
			long long diff = c - arr[b - 1];
			arr[b - 1] = c;
			seg_update(1, 0, N - 1, b - 1, diff);
		}
		// ���� ���Ͽ� ���
		else {
			cout << seg_sum(1, 0, N - 1, b - 1, c - 1) << "\n";
		}
	}

	return 0;
}