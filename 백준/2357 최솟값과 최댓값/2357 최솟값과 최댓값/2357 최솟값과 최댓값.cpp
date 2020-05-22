#include <iostream>
#include <algorithm>
using namespace std;

long long arr[400010];
long long segment_min[400010];
long long segment_max[400010];

// 세그먼트 트리 생성 - 최솟값 트리
// 인자 : 노드 번호(segment), 시작 번호(arr), 끝 번호(arr)
long long seg_min_init(int node, int start, int end) {
	if (start == end) {
		return segment_min[node] = arr[start];
	}

	int mid = (start + end) / 2;
	return segment_min[node] = min(seg_min_init(node * 2, start, mid), seg_min_init(node * 2 + 1, mid + 1, end));
}

// 세그먼트 트리 생성 - 최댓값 트리
// 인자 : 노드 번호(segment), 시작 번호(arr), 끝 번호(arr)
long long seg_max_init(int node, int start, int end) {
	if (start == end) {
		return segment_max[node] = arr[start];
	}

	int mid = (start + end) / 2;
	return segment_max[node] = max(seg_max_init(node * 2, start, mid), seg_max_init(node * 2 + 1, mid + 1, end));
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
		return segment_min[node];
	}

	// 3.	현재 범위가 구하려는 세그먼트 트리의 구간보다 크거나, 일부분만 겹치는 경우
	//		이 경우는 둘로 나누어서 탐색을 시작한다.
	int mid = (start + end) / 2;
	return min(seg_min(node * 2, start, mid, left, right), seg_min(node * 2 + 1, mid + 1, end, left, right));
}

// 세그먼트 트리 최댓값 구하기
// 인자 :	노드 번호(segment), 시작 번호(arr), 끝 번호(arr), 
//			구하려는 부분의 왼쪽 범위(segment), 구하려는 부분의 오른쪽 범위(segment)
long long seg_max(int node, int start, int end, int left, int right) {
	// 1.	현재 범위와 구하려는 세그먼트 트리의 구간이 겹치지 않는 경우 -> 0을 리턴
	if (left > end || right < start) {
		return 0;
	}

	// 2.	현재 범위가 구하려는 세그먼트 트리의 구간에 완전히 포함되는 경우 -> segment[node]를 리턴
	//		현재 범위 <= 구하려는 부분 구간 세그먼트 트리 범위
	if (left <= start && end <= right) {
		return segment_max[node];
	}

	// 3.	현재 범위가 구하려는 세그먼트 트리의 구간보다 크거나, 일부분만 겹치는 경우
	//		이 경우는 둘로 나누어서 탐색을 시작한다.
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
	
	// 세그먼트 트리를 만들자
	seg_min_init(1, 0, N - 1);
	seg_max_init(1, 0, N - 1);

	int a, b;

	// a ~ b 사이의 최솟값과 최댓값을 구하자
	for (int i = 0; i < M; i++) {
		cin >> a >> b;	
		cout << seg_min(1, 0, N-1, a-1, b-1) << " " << seg_max(1, 0, N-1, a-1, b-1) << "\n";
	}
	return 0;
}