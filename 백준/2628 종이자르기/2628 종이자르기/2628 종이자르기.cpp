#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> row;
vector<int> column;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	row.push_back(M);
	column.push_back(N);
	int C; cin >> C;

	int sw;
	int number;
	for (int i = 0; i < C; i++) {
		cin >> sw >> number;
		if (sw == 0) {
			// 가로로 자름
			row.push_back(number);
		}
		else {
			// 세로로 자름
			column.push_back(number);
		}
	}
	
	sort(row.begin(), row.end());
	sort(column.begin(), column.end());

	// 가로 중 제일 긴 길이 * 세로 중 제일 긴 길이
	int row_max = row[0];
	int column_max = column[0];
	int temp;
	for (int i = 1; i < row.size(); i++) {
		temp = row[i] - row[i - 1];
		row_max = max(row_max, temp);
	}

	for (int i = 1; i < column.size(); i++) {
		temp = column[i] - column[i - 1];
		column_max = max(column_max, temp);
	}

	int area = row_max * column_max;
	cout << area;
	return 0;
}