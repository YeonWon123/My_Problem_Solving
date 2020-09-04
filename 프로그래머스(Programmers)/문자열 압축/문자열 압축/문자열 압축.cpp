// 정답!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = s.size();

    string str1, str2;
    int i, j, k, counts, n_ans;
    for (i = 1; i <= s.size() / 2; i++) {
        str2 = ""; counts = 1; n_ans = 0;
        for (j = 0; j < s.size();) {
            str1 = "";
            for (k = 0; k < i && j < s.size(); k++) {
                str1 += s[j];
                j++;
            }

            // cout << "같은지 비교: " << str1 << " " << str2 << endl;

            if (str2 == "") {
                str2 = str1;
                continue;
            }

            if (str1 == str2) {
                counts++;
            }
            else {
                // 이게 답임!
                // cout << str2 << " " << counts << endl;
                n_ans += str2.size();
                if (counts != 1) {
                    if (counts >= 1000) {
                        n_ans += 4;
                    }
                    else if (counts >= 100) {
                        n_ans += 3;
                    }
                    else if (counts >= 10) {
                        n_ans += 2;
                    }
                    else {
                        n_ans += 1;
                    }
                }
                str2 = str1;
                counts = 1;
            }
        }
        // 이게 답임!
        // cout << str2 << " " << counts << endl << endl;
        n_ans += str2.size();
        if (counts != 1) {
            if (counts >= 1000) {
                n_ans += 4;
            }
            else if (counts >= 100) {
                n_ans += 3;
            }
            else if (counts >= 10) {
                n_ans += 2;
            }
            else {
                n_ans += 1;
            }
        }
        answer = min(answer, n_ans);
    }

    return answer;
}

int main(void)
{
    string str;
    cin >> str;
    cout << solution(str) << endl;
    return 0;
}