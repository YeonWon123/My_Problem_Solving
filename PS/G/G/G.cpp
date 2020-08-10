#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<pair<int, int>> point;// x, y ī�� ��ǥ
vector<pair<int, int>> num;  // first�� ī��� point[second]�� ����
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
		
		// ��ȣ �Ҵ�
		int y_now = 0;
		int number = 0;
		int vec_index = 0;
		int i, j;
		int sw = 0;
		// x��ǥ�� 0���� 100000���� �˻�
		for (i = 0; i < 100001; i++) {
			int c = counts[i]; if (c == 0) continue;
			// ���� counts ������ŭ �����ؾ� ��

			// ���� ���� y���� point�� ���� y���� �����ϸ�
			// �״�� ��ȣ �ο� (sw == 0)
			// �ƴ϶�� �������� ��ȣ �ο� (sw == 1)
			// �׸��� ���� y�� ����
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

		// ���� ���� �Է�, ������ �Է�
		cin >> m;
		int temp;
		cout << "��½���" << endl;
		for (j = 0; j < m; j++) {
			cin >> temp;
			cout << point[temp].first << " " << point[temp].second << "\n";
		}
		cout << "��³�" << endl;
	}

	return 0;
}