#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> indexs;

//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
class Solution {
public:
    double solution(vector<int> scores) {
        cout << fixed;
        cout.precision(11);

        sort(scores.begin(), scores.end()); // scores 배열 정렬
        // 제거를 안할 경우부터, 최대한 많은 점수를 제거하는 경우 모두를 살펴봐야 함
        double sum = 0.0;
        double average = 0.0;
        int in = 1, people = scores.size();
        int now = scores[0];
        for (int i = 0; i < scores.size(); i++) {
            sum += scores[i];
            if (now != scores[i]) {
                in++;
                now = scores[i];
            }
            indexs.push_back(in);
        }
        average = sum / people;
        cout << "원래 : " << sum << " " << people << " " << average << "\n";


        for (int i = 0; i < scores.size(); i++) {
            cout << indexs[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < scores.size(); i++) {
            cout << scores[i] << " ";
        }


        // in : 서로 다른 점수의 개수
        // 따라서, in이 홀수라면, (in / 2)번째까지 낮은/높은 점수 참가자를 제거할 수 있음
        // in이 짝수라면, (in / 2 - 1)번째까지 낮은/높은 점수 참가자를 제거할 수 있음
        int k = 0;
        if (in % 2 == 0)
            k = in / 2 - 1;
        else
            k = in / 2;
        cout << "k는 : " << k << endl;

        for (int i = 1; i <= k; i++) {
            // i번째까지 낮은/높은 점수 참가자 제거
            for (int j = 0; j < scores.size(); j++) {
                if (indexs[j] == i || indexs[j] == (in + 1 - i)) {
                    people--;
                    sum -= scores[j];
                }
            }
            cout << "i는 " << i << ", " << people << " " << sum << "\n";
            cout << "원래 average : " << average << ", 지금 : " << sum / people << "\n";
            average = (double)max(average, (double)sum / people);
            cout << "people : " << people << ", " << average << endl;
        }

        return average;
    }
};