//����Ž��
//�˰��� ���� �ذ� 8.2 p.222
//algospot ���ϵ�ī��
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//-1�� ���� ���� ������ �ʾ����� �ǹ��Ѵ�.
//1�� �ش� �Էµ��� ���� �������� �ǹ��Ѵ�.
//0�� �ش� �Էµ��� ���� �������� ������ �ǹ��Ѵ�.
int cache[101][101];
//���ϰ� ���ڿ�
string W, S;
vector<string> v;

//���ϵ�ī�� ���� W[w...]�� ���ڿ� S[s...]�� �����Ǵ��� ���θ� ��ȯ�Ѵ�.
bool matchMemoized(int w, int s)
{
    //�޸������̼�
    int& ret = cache[w][s];
    if (ret != -1) { return ret; }
    //W[w]�� S[s]�� ���糪����.
    while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
        w++;
        s++;
    }
    //���̻� ������ �� ������ �� while���� �������� Ȯ���Ѵ�.
    //2. ���� ���� �����ؼ� ���� ��� : ���ڿ��� ������� ��
    if (w == W.size()) {
        return ret = (s == S.size());
    }
    //4. *�� ������ ���� ��� : *�� �� ���ڸ� �����ؾ� ���� ��� ȣ���ϸ鼭 Ȯ���Ѵ�.
    if (W[w] == '*') {
        for (int skip = 0; skip + s <= S.size(); skip++) {
            //cout << w + 1 << " " << s + skip << " " << cache[w+1][s+skip] << "\n";
            if (matchMemoized(w + 1, s + skip)) {
                return ret = 1;
            }
        }
    }
    //3. �� ���� ��쿡�� ��� �������� �ʴ´�.
    return ret = 0;
}

//���ϵ�ī�� ���� w�� ���ڿ� s�� �����Ǵ��� ���θ� ��ȯ�Ѵ�.
bool match(const string& w, const string& s)
{
    //w[pos]�� s[pos]�� ���糪����.
    int pos = 0;
    while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos])) {
        pos++;
    }
    //���̻� ������ �� ������ �� while���� �������� Ȯ���Ѵ�.
    //2. ���� ���� �����ؼ� ���� ��� : ���ڿ��� ������� ������
    if (pos == w.size()) {
        return pos == s.size();
    }
    //4. *�� ������ ���� ��� : *�� ����ڸ� �����ؾ� ���� ���ȣ���ϸ鼭 Ȯ���Ѵ�.
    if (w[pos] == '*') {
        for (int skip = 0; pos + skip <= s.size(); skip++) {
            //cout << w.substr(pos + 1) << " " << s.substr(pos + skip) << "\n";
            if (match(w.substr(pos + 1), s.substr(pos + skip))) {
                return true;
            }
        }
    }
    //�� �� ��쿡�� ��� �������� �ʴ´�.
    return false;
}

int main()
{
    int t;
    int n;
    cin >> t;
    while (t) {
        cin >> W;
        cin >> n;
        for (int i = 0; i < n; i++) {
            memset(cache, -1, sizeof(cache));
            cin >> S;
            //if (match(W, S)) { v.push_back(S); }
            if (matchMemoized(0,0)) {
                v.push_back(S);
            }
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << '\n';
        }
        v.clear();
        t--;
    }
}