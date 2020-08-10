#include <string>
#include <vector>
using namespace std;

// res[i].first : �ĺ���, res[i].second : ��ǥ��
vector<pair<char, int> > res;

//�ٽ� �ҽ��ڵ��� ������ �ּ����� �ۼ��ϸ� �򰡿� ū ������ �˴ϴ�.
class Solution {
public:
    // str�� �ʱ�ȭ�ϴ� �Լ�
    void init(string str) {
        for (int i = 0; i < str.length(); i++) {
            res.push_back({ str[i], 0 });
        }
    }

    // ��� �ĺ��ڰ� Ż���ߴٸ� true ����, �׷��� ������ false ����
    bool allFail() {

        // ��� �ĺ��ڰ� Ż������ ��� -1 return
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

        // res �ʱ�ȭ
        if (res.size() == 0) {
            init(voters[0]);
        }

        // ��� �ĺ��ڰ� Ż���ߴ��� ���캸��
        if (allFail()) {
            return -1;
        }

        // ��ǥ����, ��ǥ�ڵ��� ��ǥ�� ���� ǥ���� �ø���.
        // ��, Ż���ڰ� 1������ ���, �� ���� ������ ������� ǥ�� �ش�.
        char target = 0;
        int max_value = 0;
        char max_target = 0;
        for (int i = 0; i < voters.size(); i++) {
            int j = 0, k = 0;
            while (true) {
                target = voters[i][j];
                //        cout << "target�� : " << target << "\n";

                for (k = 0; k < res.size(); k++) {
                    if (target == res[k].first) break;
                }

                if (res[k].second != -1) break;
                else j++;
            }

            //    cout << "���������� ��ǥ�ڴ� : " << res[k].first << "\n";
            res[k].second++;
            if (max_value < res[k].second) {
                max_value = res[k].second;
                max_target = res[k].first;
            }
        }

        // ����ڰ� �����Ǵ� ���
        if (max_value > (double)voters.size() / 2) {
            //    cout << "����?" << endl;
            //    cout << max_value << " " << (double)voters.size() / 2 << endl;
            return (int)(max_target - '0');
        }
        else {
            // Ż���� ����
            int min_value = 999999;
            // Ż���� index ����
            vector<int> min_index;
            for (int i = 0; i < res.size(); i++) {
                // �̹� Ż������ ���� �ĺ��� �� ��ǥ���� ���� ���� �ĺ��ڵ� ����
                if (min_value > res[i].second&& res[i].second != -1) {
                    min_value = res[i].second;
                    min_index.clear();
                    min_index.push_back(i);
                }
                else if (min_value == res[i].second) {
                    min_index.push_back(i);
                }
            }

            // Ż����Ŵ (res = -1�� Ż��)
            for (int i = 0; i < min_index.size(); i++) {
                res[min_index[i]].second = -1;
            }

            return solution(voters);
        }
    }
};