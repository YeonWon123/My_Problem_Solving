#include <iostream>
#include <algorithm>
using namespace std;

int arr[500000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int M, target;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> target;
		int* index1 = lower_bound(arr, arr + N, target);
		int* index2 = upper_bound(arr, arr + N, target);
		cout << index2 - index1 << " ";
	}
	return 0;
}


/*
int input[500000];
int input_d[500000];
int count_d[500000];

// 이진 탐색 함수, index를 리턴함
int BinarySearch(int start, int end, int target) {
	if (start == end) {
		if (input_d[start] == target)
			return start;
		else
			return -1;
	}
	
	int mid = (start + end) / 2;
	if (input_d[mid] == target) {
		return mid;
	}
	else if (input_d[mid] > target) {
		return BinarySearch(start, mid - 1, target);
	}
	else {
		return BinarySearch(mid + 1, end, target);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	// 입력을 다 받고 - O(n)
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	// sort후 counts한 다음 - O(n log n) + O(n)
	sort(input, input + N);
	int counts, now;
	int index = 0;
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			now = input[0];
			counts = 1;
			continue;
		}
		if (now != input[i]) {
			input_d[index] = now;
			count_d[index] = counts;
			index++;
			now = input[i];
			counts = 1;
		}
		else {
			counts++;
		}

		if (i == N - 1) {
			input_d[index] = now;
			count_d[index] = counts;
			index++;
		}
	}

//	for (int i = 0; i < index; i++) {
//		cout << i << "번째 : " << input_d[i] << " " << count_d[i] << endl;
//	}

	// 이진 탐색을 M번 수행 - O(m log n)
	int M, target, index2; 
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> target;
		index2 = BinarySearch(0, index - 1, target);
		if (index2 == -1)
			cout << 0 << " ";
		else
			cout << count_d[index2] << " ";
	}


	return 0;
}
*/