#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map<string, int> hashs;
map<string, int>::iterator iter;

// hash에 participant를 넣고, completion만큼 빼면 된다.
// 맨 마지막에 hash를 순회하면서, hash의 int값이 0이 아닌 걸 출력하자
// 시간복잡도 : T(n) = n log n + n, O(n) = n log n
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    // hash에 participant 넣기
    for (int i = 0; i < participant.size(); i++) {
        iter = hashs.find(participant[i]);
        // 기존 hash에 이미 있는 원소라면, 원소의 수를 1 증가시킴
        if (iter != hashs.end()) {
            iter->second++;
        }
        // 없다면 원소를 새로 추가, 원소의 수는 1
        else {
            pair<string, int> a;
            a.first = participant[i];
            a.second = 1;
            hashs.insert(a);
        }
    }

    // hash에서 completion을 빼기
    for (int i = 0; i < completion.size(); i++) {
        iter = hashs.find(completion[i]);
        iter->second--;
    }

    // hash를 순회하면서 hash의 int값이 0이 아니면 출력
    for (iter = hashs.begin(); iter != hashs.end(); iter++) {
        if (iter->second != 0) {
            answer = iter->first;
            break;
        }
    }

    return answer;
}

int main(void)
{
    int p_size, c_size;
    string input;
    vector<string> participant;
    vector<string> completion;
    cin >> p_size >> c_size;
    for (int i = 0; i < p_size; i++) {
        cin >> input;
        participant.push_back(input);
    }
    for (int i = 0; i < c_size; i++) {
        cin >> input;
        completion.push_back(input);
    }

    cout << solution(participant, completion);

    return 0;
}