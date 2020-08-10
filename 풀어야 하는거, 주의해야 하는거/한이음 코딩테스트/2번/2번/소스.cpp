#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

// dp[i][j] : ���ڿ� �� i��°���� j��°���� ������ ��
// "74233285"����, dp[1][4] = 4+2+3+3�� �ǹ���.
int dp[51][51] = { 0, };

//�ٽ� �ҽ��ڵ��� ������ �ּ����� �ۼ��ϸ� �򰡿� ū ������ �˴ϴ�.
class Solution {
public:
    int solution(string s) {
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (j == i)
                    dp[i][j] = (int)(s[j] - '0');
                else
                    dp[i][j] = dp[i][j - 1] + int(s[j] - '0');
            }
        }
        /*
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cout << setw(5) << dp[i][j] << " ";
            }
            cout << "\n";
        }
        */

        // k�� ���ڿ� ���� / 2�� �� ��, k�� ���� �ִ�� �� �ͺ��� 1�� �δ� �ͱ��� ����, ���� 2*K�� ����Ͽ� �׻� ¦���� �ǰ� ��
        int k = s.size() / 2;
        for (int i = k; i > 0; i--) {
            // cout << "k�� : " << i << '\n';
            for (int j = 0; j <= s.size() - 2 * i; j++) {
                // cout << j << " " << j + i -1 << " : " << j + i << " " << j + 2*i -1 << "\n";
                if (dp[j][j + i - 1] == dp[j + i][j + 2 * i - 1]) {
                    return 2 * i;
                }
            }
        }

        return 0;
    }
};