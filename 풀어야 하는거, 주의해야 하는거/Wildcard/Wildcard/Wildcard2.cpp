#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/****************** 와일드카드 문제를 해결하는 완전 탐색 알고리즘 *******************************/

// 패턴과 문자열
string W, S;

// 답을 저장
vector<string> ans;

bool match(const string& w, const string& s) {
	// w[pos]와 s[pos]를 맞춰나간다.
	int pos = 0;
	while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos])) {
		++pos;
	}

	// 더이상 대응할 수 없으면 왜 while문이 끝났는지 확인한다.
	// 2. 패턴 끝에 도달해서 끝난 경우: 문자열도 끝났어야 대응됨
	if (pos == w.size())
		return pos == s.size();

	// 4. *를 만나서 끝난 경우: *에 몇 글자를 대응해야 할지 재귀호출하면서 확인한다.
	if (w[pos] == '*')
		for (int skip = 0; pos + skip <= s.size(); ++skip) {
			if (match(w.substr(pos + 1), s.substr(pos + skip)))
				return true;
		}
	// 이 외의 경우에는 모두 대응되지 않는다.
	return false;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int C, N;
	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> W >> N;
		ans.clear();
		for (int j = 0; j < N; j++) {
			cin >> S;
			if (match(W, S)) {
				ans.push_back(S);
			}
		}
		sort(ans.begin(), ans.end());
		for (int j = 0; j < ans.size(); j++) {
			cout << ans[j] << "\n";
		}
	}

	return 0;
}