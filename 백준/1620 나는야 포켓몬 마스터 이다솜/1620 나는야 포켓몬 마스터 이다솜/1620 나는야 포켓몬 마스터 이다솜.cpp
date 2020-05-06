#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

string str[100000];
pair<string, int> str_sorted[100000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M, N; cin >> M >> N;
	for (int i = 0; i < M; i++) {
		cin >> str[i];
		str_sorted[i].first = str[i];
		str_sorted[i].second = i + 1;
	}

	sort(str_sorted, str_sorted + M);

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		int intValue = atoi(input.c_str());
		if (intValue != 0) {
			cout << str[intValue - 1] << "\n";
		}
		else {
			
			// 이진 탐색
			int start = 0;
			int end = M;
			while (true) {
				int mid = (start + end) / 2;

				//cout << start << " " << end << " " << mid << "\n";

				if (str_sorted[mid].first == input) {
					cout << str_sorted[mid].second << "\n";
					break;
				}
				else if (str_sorted[mid].first > input) {
					end = mid - 1;
				}
				else {
					start = mid + 1;
				}
			}
			
			/*
			// lower_bound 사용
			pair<string, int> now;
			now.first = input; now.second = 10000000;
			cout << str_sorted[lower_bound(str_sorted, str_sorted + M, now) - str_sorted - 1].second << "\n";
			*/
		}
	}


	return 0;
}