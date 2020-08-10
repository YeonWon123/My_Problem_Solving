//백준 17370
#include <iostream>
#include <vector>
using namespace std;

int N;
int dirY[6] = { 2,1,1,-2,-1,-1 };   //위,왼쪽위, 오른쪽위, 아래, 왼쪽아래, 오른쪽아래
int dirX[6] = { 0,-1,1,0,-1,1 };
int dir[6][2] = { {1,2},{0,4},{0,5},{4,5},{3,1},{3,2} };
vector<pair<int, int>> v;
int ans = 0;

bool isMeeting(int y, int x)
{
    int size = v.size();
    for (int i = 0; i < size - 1; i++) {
        if (v[i].first == y && v[i].second == x) {
            return true;
        }
    }
    return false;
}

void func(int state, int n)
{
    int y = v.back().first;
    int x = v.back().second;

    if (n == 0) {
    //    v.pop_back();
        if (isMeeting(y, x)) { ans++; }
        return;
    }

    if (isMeeting(y, x)) {
    //    v.pop_back();
        return;
    }

    int newY = y + dirY[dir[state][0]];
    int newX = x + dirX[dir[state][0]];
    v.push_back({ newY, newX });
    func(dir[state][0], n - 1);
    v.pop_back();

    newY = y + dirY[dir[state][1]];
    newX = x + dirX[dir[state][1]];
    v.push_back({ newY, newX });
    func(dir[state][1], n - 1);
    v.pop_back();
}

int main()
{
    cin >> N;

    //처음 위치 (0,0)
    v.push_back({ 0,0 });
    int y = v.front().first;
    int x = v.front().second;

    //위로 이동
    y += dirY[0];
    x += dirX[0];

    //현재 위치 (2,0)
    v.push_back({ y,x });

    func(0, N);

    cout << ans;
}