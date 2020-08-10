#include <string>
#include <vector>
using namespace std;

// res[i].first : 후보자, res[i].second : 득표수
vector<pair<char, int> > res;

//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
class Solution {
public:
    // str을 초기화하는 함수
    void init(string str) {
        for (int i = 0; i < str.length(); i++) {
            res.push_back({ str[i], 0 });
        }
    }

    // 모든 후보자가 탈락했다면 true 리턴, 그렇지 않으면 false 리턴
    bool allFail() {

        // 모든 후보자가 탈락했을 경우 -1 return
        int minus = 0;
        for (int i = 0; i < res.size(); i++) {
            if (res[i].second > 0) {
                res[i].second = 0;
            }
            else if (res[i].second < 0) {
                minus++;
            }
        }

        if (minus == res.size()) return true;
        else return false;
    }

    int solution(vector<string> voters) {

        // res 초기화
        if (res.size() == 0) {
            init(voters[0]);
        }

        // 모든 후보자가 탈락했는지 살펴보기
        if (allFail()) {
            return -1;
        }

        // 투표에서, 투표자들이 투표한 곳에 표수를 늘린다.
        // 단, 탈락자가 1순위일 경우, 그 다음 순위의 사람에게 표를 준다.
        char target = 0;
        int max_value = 0;
        char max_target = 0;
        for (int i = 0; i < voters.size(); i++) {
            int j = 0, k = 0;
            while (true) {
                target = voters[i][j];
                //        cout << "target은 : " << target << "\n";

                for (k = 0; k < res.size(); k++) {
                    if (target == res[k].first) break;
                }

                if (res[k].second != -1) break;
                else j++;
            }

            //    cout << "최종적으로 득표자는 : " << res[k].first << "\n";
            res[k].second++;
            if (max_value < res[k].second) {
                max_value = res[k].second;
                max_target = res[k].first;
            }
        }

        // 우승자가 결정되는 경우
        if (max_value > (double)voters.size() / 2) {
            //    cout << "결정?" << endl;
            //    cout << max_value << " " << (double)voters.size() / 2 << endl;
            return (int)(max_target - '0');
        }
        else {
            // 탈락자 결정
            int min_value = 999999;
            // 탈락자 index 저장
            vector<int> min_index;
            for (int i = 0; i < res.size(); i++) {
                // 이미 탈락하지 않은 후보자 중 득표수가 가장 낮은 후보자들 선정
                if (min_value > res[i].second&& res[i].second != -1) {
                    min_value = res[i].second;
                    min_index.clear();
                    min_index.push_back(i);
                }
                else if (min_value == res[i].second) {
                    min_index.push_back(i);
                }
            }

            // 탈락시킴 (res = -1로 탈락)
            for (int i = 0; i < min_index.size(); i++) {
                res[min_index[i]].second = -1;
            }

            return solution(voters);
        }
    }
};