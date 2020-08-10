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
	
	// union-find �����
	int s, e;
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			s = arr[i].start; e = arr[i].end; temp.push_back(arr[i].index);
		}
		else {
			if (arr[i].start >= e) {
				// ���ο� �� ������ ��
				// �켱 temp�� �������� üũ
				if (temp.size() > ans.size()) {
					// temp�� ans�� �ű�
					ans.clear();
					for (int j = 0; j < temp.size(); j++) {
						ans.push_back(temp[j]);
					}
				}
				// ���ο� temp�� ���� ����
				temp.clear();
				s = arr[i].start; e = arr[i].end; temp.push_back(arr[i].index);
			}
			else {
				// temp�� ����
				if (arr[i].end > e) e = arr[i].end;
				temp.push_back(arr[i].index);
			}
		}
	}

	if (temp.size() > ans.size()) {
		// temp�� ans�� �ű�
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