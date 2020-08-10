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
//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
class Solution {
public:

    vector<string> solution(vector<string> photo, int k, int threshold) {

        // k가 있는 곳을 찾아서, 표시를 해 둔 다음에, 그 k와 맞닿은 부분을 전부 색칠한다
        // 총 넓이가 threshold보다 크면,
        // 가장 왼쪽 좌표와, 가장 오른쪽 좌표를 구하고
        // 가장 위쪽 좌표와, 가장 아래쪽 좌표를 구한다.
        // 그 네 좌표의 중심점을 구하여 저장 후 출력한다.
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
                    //cout << "q에 들어가자" << i << ", " << j << endl;
                    // bfs 순회로 서로 맞닿아있는지 확인
                    // 맞닿아있으면 계속 순회
                    while (!q.empty()) {
                        int ny = q.front().first;
                        int nx = q.front().second;
                        q.pop();
                        temp.push_back({ ny, nx });
                        for (int kk = 0; kk < 4; kk++) {
                            if (visit[ny + dy[kk]][nx + dx[kk]] == 0 && ny + dy[kk] >= 0 && ny + dy[kk] < photo.size() && nx + dx[kk] >= 0 && nx + dx[kk] < photo[ny].size()) {
                                visit[ny + dy[kk]][nx + dx[kk]] = 1;
                                //cout << "q에 들어가자!! " << ny + dy[kk] << ", " << nx + dx[kk] << " 값은 : " << photo[ny + dy[kk]][nx+dx[kk]] << "\n";

                                if (photo[ny + dy[kk]][nx + dx[kk]] == (char)(k + '0')) {
                                    //cout << "성공!" << endl;
                                    q.push({ ny + dy[kk], nx + dx[kk] });
                                }
                            }
                        }
                        area++;
                    }
                }

                area *= 4;
                //cout << area << "\n";
                // 정답 추가
                if (area >= threshold) {
                    // 점들 중 y좌표가 가장 작은 것과 가장 큰 것 찾기
                    int y_min = 999999;
                    int y_max = -999999;

                    // 점들 중 x좌표가 가장 작은 것과 가장 큰 것 찾기
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

                    //cout << "y와 x의 값들" << "\n";
                    //cout << y_min << " " << y_max << ", " << x_min << " " << x_max << "\n";

                    // (y_min, x_min) ~ (y_max + 2, x_max + 2)
                    int y_avg = (y_min + y_max) / 2;
                    int x_avg = (x_min + x_max) / 2;
                    ans_int.push_back({ x_avg, y_avg });
                }
            }
        }

        // 정답을 sort해야 함
        sort(ans_int.begin(), ans_int.end());
        for (int i = 0; i < ans_int.size(); i++) {
            string str = to_string(ans_int[i].first) + " " + to_string(ans_int[i].second);
            ans.push_back(str);
        }

        return ans;
    }
};