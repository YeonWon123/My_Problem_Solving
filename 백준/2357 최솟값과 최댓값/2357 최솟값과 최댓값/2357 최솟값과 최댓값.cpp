#include <iostream>
#include <algorithm>
using namespace std;

long long arr[400010];
long long segment_min[400010];
long long segment_max[400010];

// ���׸�Ʈ Ʈ�� ���� - �ּڰ� Ʈ��
// ���� : ��� ��ȣ(segment), ���� ��ȣ(arr), �� ��ȣ(arr)
long long seg_min_init(int node, int start, int end) {
	if (start == end) {
		return segment_min[node] = arr[start];
	}

	int mid = (start + end) / 2;
	return segment_min[node] = min(seg_min_init(node * 2, start, mid), seg_min_init(node * 2 + 1, mid + 1, end));
}

// ���׸�Ʈ Ʈ�� ���� - �ִ� Ʈ��
// ���� : ��� ��ȣ(segment), ���� ��ȣ(arr), �� ��ȣ(arr)
long long seg_max_init(int node, int start, int end) {
	if (start == end) {
		return segment_max[node] = arr[start];
	}

	int mid = (start + end) / 2;
	return segment_max[node] = max(seg_max_init(node * 2, start, mid), seg_max_init(node * 2 + 1, mid + 1, end));
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
		return segment_min[node];
	}

	// 3.	���� ������ ���Ϸ��� ���׸�Ʈ Ʈ���� �������� ũ�ų�, �Ϻκи� ��ġ�� ���
	//		�� ���� �ѷ� ����� Ž���� �����Ѵ�.
	int mid = (start + end) / 2;
	return min(seg_min(node * 2, start, mid, left, right), seg_min(node * 2 + 1, mid + 1, end, left, right));
}

// ���׸�Ʈ Ʈ�� �ִ� ���ϱ�
// ���� :	��� ��ȣ(segment), ���� ��ȣ(arr), �� ��ȣ(arr), 
//			���Ϸ��� �κ��� ���� ����(segment), ���Ϸ��� �κ��� ������ ����(segment)
long long seg_max(int node, int start, int end, int left, int right) {
	// 1.	���� ������ ���Ϸ��� ���׸�Ʈ Ʈ���� ������ ��ġ�� �ʴ� ��� -> 0�� ����
	if (left > end || right < start) {
		return 0;
	}

	// 2.	���� ������ ���Ϸ��� ���׸�Ʈ Ʈ���� ������ ������ ���ԵǴ� ��� -> segment[node]�� ����
	//		���� ���� <= ���Ϸ��� �κ� ���� ���׸�Ʈ Ʈ�� ����
	if (left <= start && end <= right) {
		return segment_max[node];
	}

	// 3.	���� ������ ���Ϸ��� ���׸�Ʈ Ʈ���� �������� ũ�ų�, �Ϻκи� ��ġ�� ���
	//		�� ���� �ѷ� ����� Ž���� �����Ѵ�.
	int mid = (start + end) / 2;
	return max(seg_max(node * 2, start, mid, left, right), seg_max(node * 2 + 1, mid + 1, end, left, right));
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
	seg_min_init(1, 0, N - 1);
	seg_max_init(1, 0, N - 1);

	int a, b;

	// a ~ b ������ �ּڰ��� �ִ��� ������
	for (int i = 0; i < M; i++) {
		cin >> a >> b;	
		cout << seg_min(1, 0, N-1, a-1, b-1) << " " << seg_max(1, 0, N-1, a-1, b-1) << "\n";
	}
	return 0;
}