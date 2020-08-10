#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

int N;

int pizza[1001];
// dp[i][j] : i ~ j ���̿� ī�尡 ���� �� Alice�� ���� �� �ִ� �ְ� ����
// dp[i][i] = card[i];
// dp[i][j] = max(dp[i+1][j] + card[i], dp[i][j-1] + card[j])
//int dp[1001][1001];
int sum[1001];


//i~j������ ���� ���� �� first�� ���ڸ� ���� �� �ִ� �ּ��� ����
void recursion(int i, int j, float& first, float& second) {
    cout << i << "\t" << j << "\t" << first << "\t" << second << endl;
    //ó�� ���������� ���� ���: ���� ������ ũ��� �����̱� ������ ������ silver�� �ѹ��ۿ� ���ڸ� �������� ����.
    if (i == -1) {
        first += pizza[j];
        if (j == 0) { recursion(1, N - 1, second, first); }
        else if (j == N - 1) { recursion(0, N - 2, second, first); }
        else { recursion(j + 1, j - 1, second, first); }
        return;
    }
    //ó�� ���� ���������� ���� ���: �� ���� ������ ��� �Ծ��µ� ������ ���� ���ڸ� �� ���� �������� �ٽ� �������� ���� ����
    else {
        int part;
        /*if (dp[i][j] != 0) {
            return dp[i][j];
        }*/
        if (i == j) {
            first += pizza[i];
            //return part;
            return;
        }
        else if (i < j) {
            float temp_second;
            //i��° ���������� �����ϴ� ���
            float temp_i = first + pizza[i];
            temp_second = second;
            if (temp_i > temp_second) { recursion(i + 1, j, temp_second, temp_i); }
            else { recursion(i + 1, j, temp_i, temp_second); }
            //j��° ���������� �����ϴ� ���
            float temp_j = first + pizza[j];
            temp_second = second;
            if (temp_j > temp_second) { recursion(i, j - 1, temp_second, temp_j); }
            else { recursion(i, j - 1, temp_j, temp_second); }
            //int res2 = max(res - recursion(i + 1, j), res - recursion(i, j - 1));
            //dp[i][j] = res2;
            first = temp_i > temp_j ? temp_i : temp_j;
            return;
        }
        else {  //i > j
            float temp_second;
            //i��° ���������� �����ϴ� ���
            float temp_i = first + pizza[i];
            temp_second = second;
            if (temp_i > second) { recursion((i + 1) % N, j, temp_second, temp_i); }
            else { recursion((i + 1) % N, j, temp_i, temp_second); }
            //j��° ���������� �����ϴ� ���
            float temp_j = first + pizza[j];
            temp_second = second;
            if (temp_j > second) { recursion(i, (j - 1 + N) % N, temp_second, temp_j); }
            else { recursion(i, (j - 1 + N) % N, temp_j, temp_second); }
            //res2 = max(res - recursion((i + 1) % N, j), res - recursion(i, (j - 1 + N) % N));
            //dp[i][j] = res2;
            first = temp_i > temp_j ? temp_i : temp_j;
            return;
        }
        /*if (dp[i][j] != 0) return dp[i][j];

        if (i == j) return card[i];
        else {
            int res = 0;
            if (i == 0) res = sum[j];
            else res = sum[j] - sum[i - 1];
            int res2 = max(res - recursion(i + 1, j), res - recursion(i, j - 1));
            dp[i][j] = res2;
            return res2;
        }*/
    }
}
int main() {
    memset(pizza, 0, sizeof(pizza));
    //memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> pizza[i];
        sum[i] = pizza[i];
        if (i != 0) { sum[i] += sum[i - 1]; }
    }
    int ans = 0;
    if (N == 1) { ans = pizza[0]; }
    else {
        for (int i = 0; i < N; i++) {
            float silver = 0;
            float bronze = 0.5;
            recursion(-1, i, silver, bronze);
            ans = max((int)silver, ans);
        }
    }
    cout << ans;
    return 0;
}