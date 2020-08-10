#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> indexs;

//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
double solution(vector<int> scores) {
    sort(scores.begin(), scores.end());
    double sum = 0.0;
    double average = 0.0;
    int in = 1;
    int people = scores.size();
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
    cout << average << "\n";
    int k = 0;
    if (in % 2 == 0) {
        k = in / 2 - 1;
    }
    else {
        k = in / 2;
    }
    
    cout << k << endl;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < scores.size(); j++) {
            if (indexs[j] == i || indexs[j] == (in + 1 - i)) {
                people--;
                sum -= scores[j];
            }
        }
    }
    cout << average << " " << (double)sum / people << endl;
    average = max(average, (double)sum / people);
    return average;
}


int main(void) {
    vector<int> scores;
    int n;
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        scores.push_back(temp);
    }
    cout << solution(scores);
}