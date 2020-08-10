#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> indexs;

//�ٽ� �ҽ��ڵ��� ������ �ּ����� �ۼ��ϸ� �򰡿� ū ������ �˴ϴ�.
class Solution {
public:
    double solution(vector<int> scores) {
        cout << fixed;
        cout.precision(11);

        sort(scores.begin(), scores.end()); // scores �迭 ����
        // ���Ÿ� ���� ������, �ִ��� ���� ������ �����ϴ� ��� ��θ� ������� ��
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
        cout << "���� : " << sum << " " << people << " " << average << "\n";


        for (int i = 0; i < scores.size(); i++) {
            cout << indexs[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < scores.size(); i++) {
            cout << scores[i] << " ";
        }


        // in : ���� �ٸ� ������ ����
        // ����, in�� Ȧ�����, (in / 2)��°���� ����/���� ���� �����ڸ� ������ �� ����
        // in�� ¦�����, (in / 2 - 1)��°���� ����/���� ���� �����ڸ� ������ �� ����
        int k = 0;
        if (in % 2 == 0)
            k = in / 2 - 1;
        else
            k = in / 2;
        cout << "k�� : " << k << endl;

        for (int i = 1; i <= k; i++) {
            // i��°���� ����/���� ���� ������ ����
            for (int j = 0; j < scores.size(); j++) {
                if (indexs[j] == i || indexs[j] == (in + 1 - i)) {
                    people--;
                    sum -= scores[j];
                }
            }
            cout << "i�� " << i << ", " << people << " " << sum << "\n";
            cout << "���� average : " << average << ", ���� : " << sum / people << "\n";
            average = (double)max(average, (double)sum / people);
            cout << "people : " << people << ", " << average << endl;
        }

        return average;
    }
};