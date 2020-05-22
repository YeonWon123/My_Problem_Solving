#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1000001];
long long segment[4000001];

// 세그먼트 트리 생성 - 최솟값 트리
// 인자 : 노드 번호(segment), 시작 번호(arr), 끝 번호(arr)
long long seg_init(int node, int start, int end) {
	if (start == end) {
		return segment[node] = arr[start];
	}

	int mid = (start + end) / 2;
	return segment[node] = min(seg_init(node * 2, start, mid), seg_init(node * 2 + 1, mid + 1, end));
}

// 세그먼트 트리 업데이트
// 인자 : 노드 번호(segment), 시작 번호(arr), 끝 번호(arr), 바꾸고자 하는 노드 번호(arr), 차이(diff)
// 차이(diff)의 경우 바꾸기 전의 값과 바꾼 값의 차이를 나타낸다.
void seg_update(int node, int start, int end, int index, long long new_value) {
	// 시작 번호와 끝 번호 사이에 바꾸고자 하는 노드가 없으면 함수 종료
	if (!(start <= index && index <= end)) return;

	// 전체 구간 최솟값을 갱신시킴
	segment[node] = min(segment[node], new_value);

	// 바꾸어야 하는 구간 합일 경우 diff를 더함
	if (start != end) {
		int mid = (start + end) / 2;
		seg_update(node * 2, start, mid, index, new_value);
		seg_update(node * 2 + 1, mid + 1, end, index, new_value);
	}

}

// 세그먼트 트리 최솟값 구하기
// 인자 :	노드 번호(segment), 시작 번호(arr), 끝 번호(arr), 
//			구하려는 부분의 왼쪽 범위(segment), 구하려는 부분의 오른쪽 범위(segment)
long long seg_min(int node, int start, int end, int left, int right) {
	// 1.	현재 범위와 구하려는 세그먼트 트리의 구간이 겹치지 않는 경우 -> 1000000001을 리턴
	if (left > end || right < start) {
		return 1000000001;
	}

	// 2.	현재 범위가 구하려는 세그먼트 트리의 구간에 완전히 포함되는 경우 -> segment[node]를 리턴
	//		현재 범위 <= 구하려는 부분 구간 세그먼트 트리 범위
	if (left <= start && end <= right) {
		return segment[node];
	}

	// 3.	현재 범위가 구하려는 세그먼트 트리의 구간보다 크거나, 일부분만 겹치는 경우
	//		이 경우는 둘로 나누어서 탐색을 시작한다.
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

	// 세그먼트 트리를 만들자
	seg_init(1, 0, N - 1);

	int a, b;

	// a ~ b 사이의 최솟값을 구하자
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << seg_min(1, 0, N - 1, a - 1, b - 1) << "\n";
	}
	return 0;
}