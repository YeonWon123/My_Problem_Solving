#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/****************** ���ϵ�ī�� ������ �ذ��ϴ� ���� ��ȹ�� �˰��� *******************************/

// -1�� ���� ���� ������ �ʾ����� �ǹ��Ѵ�.
// 1�� �ش� �Էµ��� ���� �������� �ǹ��Ѵ�.
// 0�� �ش� �Էµ��� ���� �������� ������ �ǹ��Ѵ�.
int cache[101][101];
// ���ϰ� ���ڿ�
string W, S;
// ����� �����س��� vector
vector<string> ans;

// ���ϵ�ī�� ���� W[w..]�� ���ڿ� S[s..]�� �����Ǵ��� ���θ� ��ȯ�Ѵ�.
// �ð� ���⵵ : O(n^3)
bool matchMemoized(int w, int s) {
	// �޸������̼�
	int& ret = cache[w][s];
	if (ret != -1) return ret;
	// W[w]�� S[s]�� ���糪����.
	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
		++w;
		++s;
	}

	// ���̻� ������ �� ������ �� while���� �������� Ȯ���Ѵ�.
	// 2. ���� ���� �����ؼ� ���� ���: ���ڿ��� ������� �� - ���̰� ���ƾ� �Ѵٴ� �̾߱�
	if (w == W.size()) return ret = (s == S.size());

	// 4. *�� ������ ���� ���: *�� �� ���ڸ� �����ؾ� ���� ��� ȣ���ϸ鼭 Ȯ���Ѵ�.
	if (W[w] == '*') {
		for (int skip = 0; skip + s <= S.size(); skip++) {
			if (matchMemoized(w + 1, s + skip))
				return ret = 1;
		}
	}

	// 3. �� ���� ��쿡�� ��� �������� �ʴ´�.
	return ret = 0;
}

// ���ϵ�ī�� ���� W[w..]�� ���ڿ� S[s..]�� �����Ǵ��� ���θ� ��ȯ�Ѵ�.
// �ð� ���⵵ : O(n^2)
bool matchMemoized2(int w, int s) {
	// �޸������̼�
	int& ret = cache[w][s];
	if (ret != -1) return ret;
	// W[w]�� S[s]�� ���糪����.
	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
		return ret = matchMemoized2(w + 1, s + 1);
	}

	// ���̻� ������ �� ������ �� while���� �������� Ȯ���Ѵ�.
	// 2. ���� ���� �����ؼ� ���� ���: ���ڿ��� ������� �� - ���̰� ���ƾ� �Ѵٴ� �̾߱�
	if (w == W.size()) return ret = (s == S.size());

	// 4. *�� ������ ���� ���: *�� �� ���ڸ� �����ؾ� ���� ��� ȣ���ϸ鼭 Ȯ���Ѵ�.
	if (W[w] == '*') {
		if (matchMemoized(w + 1, s + skip))
			return ret = 1;
	}

	// 3. �� ���� ��쿡�� ��� �������� �ʴ´�.
	return ret = 0;
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
			// cache �迭 �ʱ�ȭ
			memset(cache, -1, sizeof(cache));
			if (matchMemoized(0, 0)) {
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