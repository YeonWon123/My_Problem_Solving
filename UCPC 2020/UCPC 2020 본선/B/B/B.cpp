



/*

B�� ��������.

N�� M�� ���� ���� ��

�Ʒ��ʿ��� i��° ���� ���ʿ��� j���� �� i, j
���� �� �濣 R, U
������ �濡�� ����
�̹��� �� ���� i, j�϶� R�� �����ִٸ� i, j + 1�̵�
U��� i + 1, j �̵�

���� ������ ����� ��Ģ
1. ������ ������ �����ϴ� K������ ����� �̸� ����� �� ��Ͽ� ���ĺ� �빮���� ó�� K������ �ϳ� ����.
      �� ����� R�� U�θ� �̷���� ���� M�� ���ڿ��̴�.
2. ���ĺ� �빮���� ó�� K������ �̷���� ���� N�� ���ڿ��� ���� ��, i��° ���ڿ� �����Ǵ� ������� ������ �Ʒ����� i��° ���� �����.

���� ���� ������ �� N, M ������ -> ������ ����
   ���� ��ġ�� ���� ���� �Ұ����Ҽ���.

���� �������� ���� �濡 ���� ������ ���� ���� ��ϱ�?

1. ����
   �Է�:
      ���� �� N
      �� M
      ��� ���� K

      K���� �ٿ� R�Ǵ� U�� �̷���� ���� M�� ���ڿ� �־���.
      i��° ���� i��° ���ĺ� �빮�ڿ� ����.

      ���ĺ� �빮���� ó�� K������ �̷���� ���� N�� ���ڿ� �־���.
      j��° ���ڴ� ������ �Ʒ����� j��° ���� �����ϴ� ����� �ǹ��Ѵ�.

   ���:
      (N, M)�� ������ �� �ִ� ���� ���� ������ ����Ѵ�.
      ����) �� �浵 ���۹��� �� �� �ִ�

2. �籸��
   N�� M���� ��������
   �� ��ġ�� ���� ���ÿ� ���� �̵�.
   ���� ���� ��ܿ� ������ �� �ִ� ��ġ�� ����?

*/



// #include <bits/stdc++.h>

#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<queue>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int N; // �� 
int M; // �� 
int K; // ����� ����, �ʿ� ����?
string hang;
string last_str;

enum Dir {
    R,
    U,
};

// ����, �ϴ� ����.
int dir_x[2] = { -1, 0 }; // ��������
int dir_y[2] = { 0, 1 }; // �Ʒ���

typedef struct _pos {
    int y, x;
}Pos;


vector<string> jido; // jido[i][j] i��° ���Ĺ�(0���� ����)���� ����
vector<vector<bool>> maps; // ���� ���� ����. R = 0 U = 1. maps[y][x] -> y�� x��. ���� ���� 0, 0

long long min_x, max_x; // ���� ���� �࿡�� ������ ������ ���� ������, ������.

long long ans;


void travel() {
    // ���� -> ���� ���. y = 0, x = M - 1
    // �������� �� ����. ���� ������ max_x = x, U�� ���������� min_x-- ����.
    // min_x���� max_x���� ��� �����ҿ� ������ �� �ִ� �Ʒ� ���ҵ��� ã�´�.
    // �� ���ҵ��� �ݵ�� 
    // �Ʒ� ���ҵ��� ���� ���� ���Ұ� mmax_x�̰�, �� ���ҵ��� ���� ���� ģ������ �������� �� ���鼭 min_x-- ����
    // �Ʒ� ���� ���� ������ �ݺ��Ѵ�.

    Pos now = { 0, M - 1 }; // ���� ��ܿ��� �����Ѵ�. y�� x��
    bool type;
    max_x = now.x; // �ʱⰪ
    min_x = now.x;
    bool exist = true;
    for (int n = 0; n < N; n++) // ���� ���� ���� �������� ���� ����.
    {
        //printf("(%d, %d ~ %d): %d\n", n, min_x, max_x, ans);
        if (exist == false) // ���� ���� ������ �Ʒ� ���� ���� .
            break;

        for (int i = min_x - 1; i >= 0; --i) // ���� ���� ģ���� ���� ģ������ �������� �� ����. �� ���� ���� ģ���� �� �������� �� �ʿ� ����.
        {
            type = maps[n][i];
            if (type == U) // U�� ������ ���̻� �� �ʿ� ����.
                break;
            else {
                min_x--;
            }
        }

        ans += max_x - min_x + 1; // ���� �࿡�� ��ȿ�� ������ ���� �߰��Ѵ�.


        if (n >= N - 1) // ������ ����  �Ⱥ��� ��
            break;
        // �� ģ���鿡�� ���� ���� ������ �Ʒ��� ���ҵ� �� ���� �����ʰ� ���� ������ ���Ѵ�. �� ���̴� ���� ���࿡ ���� ����.

        // ���� ���� ã��
        exist = false; // ���� �࿡�� ���� ������ �� �� �ִ°� �����ϴ���
        for (int i = min_x - 1; i >= 0; i--)
        {
            type = maps[n + 1][i]; // �Ʒ� ������ Ÿ��
            if (type == U) { // �̰Ÿ� ��
                min_x = i;
                exist = true;
                break;
            }
        }
        // ���� ������ ã��
        for (int i = max_x; i >= min_x; i--)
        {
            type = maps[n + 1][i]; // �Ʒ� ������ Ÿ��
            if (type == U) { // �̰Ÿ� ��
                max_x = i;
                exist = true;
                break;
            }
        }
    }

}

void solve() {
    cin >> N >> M >> K;


    jido.reserve(30);
    maps.reserve(200001);

    for (int i = 0; i < N + 2; i++) // ���� ������ �޴´�. ���� ���� N���� ���� �� �ִ�. ��� Ȯ������?
    {
        cin >> hang; // ���� ���� �޾ƿ´�.

        if (cin.eof()) { // �޾ƿ� ���� ������ ���̸� �̰� �Žñ���.
            last_str = hang;
            break;
        }
        else {
            jido.push_back(hang);
        }
    }

    for (int i = 0; i < last_str.length(); i++) // �� ���ĺ��� ���ĺ��� �ش��ϴ� �� ���·� ���� �ۼ�.
    {
        char now_line = last_str[last_str.length() - i - 1] - 'A'; // ���� ���� ���¸� ��Ÿ���� ����. �Ʒ������ �־����� -> �Ųٷ� ����. �� ������? jido[i]�� �ִ�.
        maps.push_back(vector<bool>());
        for (int j = 0; j < jido[now_line].length(); j++)
        {
            maps[i].push_back(jido[now_line][j] == 'R' ? R : U);
        }
    }

    travel();

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}