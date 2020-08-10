#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<pair<int, int>> point;// x, y 카페 좌표
vector<pair<int, int>> num;  // first번 카페는 point[second]에 있음
int counts[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	int n, m;
	while (t--) {
		memset(counts, 0, sizeof(counts));
		num.clear();
		point.clear();
		cin >> n;
		int x, y;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			counts[x]++;
			num.push_back({ 0, i });
			point.push_back({ x,y });
		}
		sort(point.begin(), point.end());

		
		for (int i = 0; i < n; i++) {
			cout << point[i].first << " " << point[i].second << " " << "\n";
		}
		
		// 번호 할당
		int y_now = 0;
		int number = 0;
		int vec_index = 0;
		int i, j;
		int sw = 0;
		// x좌표를 0부터 100000까지 검색
		for (i = 0; i < 100001; i++) {
			int c = counts[i]; if (c == 0) continue;
			// 나온 counts 개수만큼 수행해야 함

			// 만약 현재 y값과 point의 최초 y값이 동일하면
			// 그대로 번호 부여 (sw == 0)
			// 아니라면 역순으로 번호 부여 (sw == 1)
			// 그리고 다음 y값 지정
			if (y_now == point[vec_index].second) sw = 0;
			else sw = 1;

			if (sw == 0) {
				for (j = vec_index; j < vec_index + c; j++) {
					num[j].first = number;
					number++;
				}
				y_now = num[j - 1].second;
			}
			else {
				for (j = vec_index + c - 1; j >= vec_index; j--) {
					num[j].first = number;
					number++;
				}
				y_now = num[j].second;
			}
			vec_index += c;
		}

		sort(num.begin(), num.end());

		// 정수 개수 입력, 정수들 입력
		cin >> m;
		int temp;
		cout << "출력시작" << endl;
		for (j = 0; j < m; j++) {
			cin >> temp;
			cout << point[temp].first << " " << point[temp].second << "\n";
		}
		cout << "출력끝" << endl;
	}

	return 0;
}