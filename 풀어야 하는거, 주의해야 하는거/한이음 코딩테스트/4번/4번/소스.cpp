#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int visit[50][50] = { 0, };

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
queue<pair<int, int> > q;
/*
std::string to_string(int i) {
    std::stringstream ss;
    ss << i;
    return ss.str();
}
*/
//�ٽ� �ҽ��ڵ��� ������ �ּ����� �ۼ��ϸ� �򰡿� ū ������ �˴ϴ�.
class Solution {
public:

    vector<string> solution(vector<string> photo, int k, int threshold) {

        // k�� �ִ� ���� ã�Ƽ�, ǥ�ø� �� �� ������, �� k�� �´��� �κ��� ���� ��ĥ�Ѵ�
        // �� ���̰� threshold���� ũ��,
        // ���� ���� ��ǥ��, ���� ������ ��ǥ�� ���ϰ�
        // ���� ���� ��ǥ��, ���� �Ʒ��� ��ǥ�� ���Ѵ�.
        // �� �� ��ǥ�� �߽����� ���Ͽ� ���� �� ����Ѵ�.
        vector<string> ans;
        vector<pair<int, int> > ans_int;
        vector<pair<int, int> > temp;
        for (int i = 0; i < photo.size(); i++) {
            for (int j = 0; j < photo[i].size(); j++) {
                int area = 0;
                if (photo[i][j] == (char)(k + '0') && visit[i][j] == 0) {
                    temp.clear();
                    visit[i][j] = 1;
                    q.push({ i, j });
                    //cout << "q�� ����" << i << ", " << j << endl;
                    // bfs ��ȸ�� ���� �´���ִ��� Ȯ��
                    // �´�������� ��� ��ȸ
                    while (!q.empty()) {
                        int ny = q.front().first;
                        int nx = q.front().second;
                        q.pop();
                        temp.push_back({ ny, nx });
                        for (int kk = 0; kk < 4; kk++) {
                            if (visit[ny + dy[kk]][nx + dx[kk]] == 0 && ny + dy[kk] >= 0 && ny + dy[kk] < photo.size() && nx + dx[kk] >= 0 && nx + dx[kk] < photo[ny].size()) {
                                visit[ny + dy[kk]][nx + dx[kk]] = 1;
                                //cout << "q�� ����!! " << ny + dy[kk] << ", " << nx + dx[kk] << " ���� : " << photo[ny + dy[kk]][nx+dx[kk]] << "\n";

                                if (photo[ny + dy[kk]][nx + dx[kk]] == (char)(k + '0')) {
                                    //cout << "����!" << endl;
                                    q.push({ ny + dy[kk], nx + dx[kk] });
                                }
                            }
                        }
                        area++;
                    }
                }

                area *= 4;
                //cout << area << "\n";
                // ���� �߰�
                if (area >= threshold) {
                    // ���� �� y��ǥ�� ���� ���� �Ͱ� ���� ū �� ã��
                    int y_min = 999999;
                    int y_max = -999999;

                    // ���� �� x��ǥ�� ���� ���� �Ͱ� ���� ū �� ã��
                    int x_min = 999999;
                    int x_max = -999999;



                    for (int k = 0; k < temp.size(); k++) {
                        int ny = temp[k].first;
                        int nx = temp[k].second;

                        if (y_min > ny) y_min = ny;
                        if (y_max < ny) y_max = ny;
                        if (x_min > nx) x_min = nx;
                        if (x_max < nx) x_max = nx;
                    }
                    y_min = y_min * 2;
                    y_max = y_max * 2 + 2;
                    x_min = x_min * 2;
                    x_max = x_max * 2 + 2;

                    //cout << "y�� x�� ����" << "\n";
                    //cout << y_min << " " << y_max << ", " << x_min << " " << x_max << "\n";

                    // (y_min, x_min) ~ (y_max + 2, x_max + 2)
                    int y_avg = (y_min + y_max) / 2;
                    int x_avg = (x_min + x_max) / 2;
                    ans_int.push_back({ x_avg, y_avg });
                }
            }
        }

        // ������ sort�ؾ� ��
        sort(ans_int.begin(), ans_int.end());
        for (int i = 0; i < ans_int.size(); i++) {
            string str = to_string(ans_int[i].first) + " " + to_string(ans_int[i].second);
            ans.push_back(str);
        }

        return ans;
    }
};