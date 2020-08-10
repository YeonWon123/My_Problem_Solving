// wrong answer

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point {
	int start;
	int end;
	int index;
};

bool compare(point a, point b) {
	if (a.start != b.start) return a.start < b.start;
	else return a.end < b.end;
}

point arr[300000];

vector<int> ans;
vector<int> temp;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].start >> arr[i].end;
		arr[i].index = i+1;
	}

	sort(arr, arr + N, compare);
	
	for (int i = 0; i < N; i++) {
		cout << arr[i].start << " " << arr[i].end << " " << arr[i].index << endl;
	}
	
	// union-find 만들기
	int s, e;
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			s = arr[i].start; e = arr[i].end; temp.push_back(arr[i].index);
		}
		else {
			if (arr[i].start >= e) {
				// 새로운 걸 만들어야 함
				// 우선 temp가 정답인지 체크
				if (temp.size() > ans.size()) {
					// temp를 ans에 옮김
					ans.clear();
					for (int j = 0; j < temp.size(); j++) {
						ans.push_back(temp[j]);
					}
				}
				// 새로운 temp를 만들어서 넣음
				temp.clear();
				s = arr[i].start; e = arr[i].end; temp.push_back(arr[i].index);
			}
			else {
				// temp에 넣음
				if (arr[i].end > e) e = arr[i].end;
				temp.push_back(arr[i].index);
			}
		}
	}

	if (temp.size() > ans.size()) {
		// temp를 ans에 옮김
		ans.clear();
		for (int j = 0; j < temp.size(); j++) {
			ans.push_back(temp[j]);
		}
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}