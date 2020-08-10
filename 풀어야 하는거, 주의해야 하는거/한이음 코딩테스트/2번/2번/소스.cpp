#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

// dp[i][j] : 문자열 중 i번째부터 j번째까지 숫자의 합
// "74233285"에서, dp[1][4] = 4+2+3+3을 의미함.
int dp[51][51] = { 0, };

//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
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

        // k를 문자열 길이 / 2로 한 뒤, k의 값을 최대로 둔 것부터 1로 두는 것까지 수행, 답은 2*K로 출력하여 항상 짝수가 되게 함
        int k = s.size() / 2;
        for (int i = k; i > 0; i--) {
            // cout << "k는 : " << i << '\n';
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