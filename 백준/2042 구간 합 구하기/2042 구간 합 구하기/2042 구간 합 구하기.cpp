// 세그먼트 트리를 이용해 보자
#include <iostream>
using namespace std;

long long arr[1000001];
long long segment[4000001];

// 세그먼트 트리 생성
// 인자 : 노드 번호(segment), 시작 번호(arr), 끝 번호(arr)
long long seg_init(int node, int start, int end) {
	if (start == end) {
		return segment[node] = arr[start];
	}

	int mid = (start + end) / 2;
	return segment[node] = seg_init(node * 2, start, mid) + seg_init(node * 2 + 1, mid + 1, end);
}

// 세그먼트 트리 업데이트
// 인자 : 노드 번호(segment), 시작 번호(arr), 끝 번호(arr), 바꾸고자 하는 노드 번호(arr), 차이(diff)
// 차이(diff)의 경우 바꾸기 전의 값과 바꾼 값의 차이를 나타낸다.
void seg_update(int node, int start, int end, int index, long long diff) {
	// 시작 번호와 끝 번호 사이에 바꾸고자 하는 노드가 없으면 함수 종료
	if (!(start <= index && index <= end)) return;

	// 전체 구간 합도 diff만큼 증가시킴 (이때 diff는 음수일 수도 있음)
	segment[node] += diff;

	// 바꾸어야 하는 구간 합일 경우 diff를 더함
	if (start != end) {
		int mid = (start + end) / 2;
		seg_update(node * 2, start, mid, index, diff);
		seg_update(node * 2 + 1, mid + 1, end, index, diff);
	}

}

// 세그먼트 트리 합 구하기
// 인자 :	노드 번호(segment), 시작 번호(arr), 끝 번호(arr), 
//			구하려는 부분 합의 왼쪽 범위(segment), 구하려는 부분 합의 오른쪽 범위(segment)
long long seg_sum(int node, int start, int end, int left, int right) {
	// 1.	현재 범위와 구하려는 세그먼트 트리의 합이 겹치지 않는 경우 -> 0을 리턴
	if (left > end || right < start) {
		return 0;
	}

	// 2.	현재 범위가 구하려는 세그먼트 트리의 합에 완전히 포함되는 경우 -> segment[node]를 리턴
	//		현재 범위 <= 구하려는 부분 합 세그먼트 트리 범위
	if (left <= start && end <= right) {
		return segment[node];
	}

	// 3.	현재 범위가 구하려는 세그먼트 트리의 합보다 크거나, 일부분만 겹치는 경우
	//		이 경우는 둘로 나누어서 탐색을 시작한다.
	int mid = (start + end) / 2;
	return seg_sum(node * 2, start, mid, left, right) + seg_sum(node * 2 + 1, mid + 1, end, left, right);
}

int main(void) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	// 입력을 받자
	// 입력받는 배열의 index는 0부터 N-1까지
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// 세그먼트 트리를 만들어 보자
	// 재귀함수로 구현하는 것이 좋음!
	// 세그먼트 트리의 index는 1부터 시작 (node번호가 1부터 시작)
	seg_init(1, 0, N - 1);

	// 다 만들었으면 입력을 받으면서 동작을 수행하자
	int a, b, c;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		// 갱신(update)
		if (a == 1) {
			// b번째 수를 c로 바꿈
			long long diff = c - arr[b - 1];
			arr[b - 1] = c;
			seg_update(1, 0, N - 1, b - 1, diff);
		}
		// 합을 구하여 출력
		else {
			cout << seg_sum(1, 0, N - 1, b - 1, c - 1) << "\n";
		}
	}

	return 0;
}