#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string str1[500000];
string str2[500000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str1[i];
	}
	
	sort(str1, str1 + N);

	string temp;
	int ans = 0;
	for (int i = 0; i < M; i++) {
		cin >> temp;

		// ÀÌÁø Å½»ö
		int start = 0;
		int end = M;
		while (true) {
			if (start > end) break;
			int mid = (start + end) / 2;

	//		cout << start << " " << end << " " << mid << "\n";

			if (str1[mid] == temp) {
				str2[ans] = temp;
				ans++;
				break;
			}
			else if (str1[mid] > temp) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}

	sort(str2, str2 + ans);

	cout << ans << "\n";
	for (int i = 0; i < ans; i++) {
		cout << str2[i] << "\n";
	}

	return 0;
}