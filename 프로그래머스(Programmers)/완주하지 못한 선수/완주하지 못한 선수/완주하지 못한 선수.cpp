#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map<string, int> hashs;
map<string, int>::iterator iter;

// hash�� participant�� �ְ�, completion��ŭ ���� �ȴ�.
// �� �������� hash�� ��ȸ�ϸ鼭, hash�� int���� 0�� �ƴ� �� �������
// �ð����⵵ : T(n) = n log n + n, O(n) = n log n
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    // hash�� participant �ֱ�
    for (int i = 0; i < participant.size(); i++) {
        iter = hashs.find(participant[i]);
        // ���� hash�� �̹� �ִ� ���Ҷ��, ������ ���� 1 ������Ŵ
        if (iter != hashs.end()) {
            iter->second++;
        }
        // ���ٸ� ���Ҹ� ���� �߰�, ������ ���� 1
        else {
            pair<string, int> a;
            a.first = participant[i];
            a.second = 1;
            hashs.insert(a);
        }
    }

    // hash���� completion�� ����
    for (int i = 0; i < completion.size(); i++) {
        iter = hashs.find(completion[i]);
        iter->second--;
    }

    // hash�� ��ȸ�ϸ鼭 hash�� int���� 0�� �ƴϸ� ���
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