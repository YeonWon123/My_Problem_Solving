#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/****************** ���ϵ�ī�� ������ �ذ��ϴ� ���� Ž�� �˰��� *******************************/

// ���ϰ� ���ڿ�
string W, S;

// ���� ����
vector<string> ans;

bool match(const string& w, const string& s) {
	// w[pos]�� s[pos]�� ���糪����.
	int pos = 0;
	while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos])) {
		++pos;
	}

	// ���̻� ������ �� ������ �� while���� �������� Ȯ���Ѵ�.
	// 2. ���� ���� �����ؼ� ���� ���: ���ڿ��� ������� ������
	if (pos == w.size())
		return pos == s.size();

	// 4. *�� ������ ���� ���: *�� �� ���ڸ� �����ؾ� ���� ���ȣ���ϸ鼭 Ȯ���Ѵ�.
	if (w[pos] == '*')
		for (int skip = 0; pos + skip <= s.size(); ++skip) {
			if (match(w.substr(pos + 1), s.substr(pos + skip)))
				return true;
		}
	// �� ���� ��쿡�� ��� �������� �ʴ´�.
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