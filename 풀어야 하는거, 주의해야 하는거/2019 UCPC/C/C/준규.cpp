#include <iostream>
#include <vector>
using namespace std;

int N;
int start_y = 22;
int start_x = 22;

vector<pair <int, int>> v_visit;

bool isMeeting(int y, int x)
{
    for (int i = 0; i < v_visit.size(); i++)
    {
        if (v_visit[i].first == y && v_visit[i].second == x)
            return true;
    }
    return false;
}

bool canMove(int y, int x)
{
    for (int i = 0; i < v_visit.size() - 1; i++)
    {
        if (v_visit[i].first == y && v_visit[i].second == x)
            return false;
    }
    return true;
}

int recursion(int now_y, int now_x, int n_move)
{
    /*
        ���� ��ġ�� ���� �� �ִ� ��ġ�ΰ�?
            n_move�� ä���°�?
                ��θ��� �����°�?
                return 1
                ��θ��� �� �����°�?
                return 0
            n_move�� �� ä���°�?
                recursion
        ���� �� ���� ��ġ�ΰ�?
            return 0
    */

    int ret = 0;

    if (n_move == N)
    {
        if (isMeeting(now_y, now_x))
            return 1;
        else
            return 0;
    }
    else
    {
        /*
        ���� ������ �� ����
                      ��      ��
            y + x��   ¦��    Ȧ��
        */
        if (canMove(now_y, now_x + 1))
        {
            v_visit.emplace_back(now_y, now_x + 1);
            ret += recursion(now_y, now_x + 1, n_move + 1);
            v_visit.pop_back();
        }

        if (canMove(now_y, now_x - 1))
        {
            v_visit.emplace_back(now_y, now_x - 1);
            ret += recursion(now_y, now_x - 1, n_move + 1);
            v_visit.pop_back();
        }

        if (canMove(now_y + 1, now_x))
        {
            v_visit.emplace_back(now_y + 1, now_x);
            ret += recursion(now_y + 1, now_x, n_move + 1);
            v_visit.pop_back();
        }
        else
        {
            if (canMove(now_y - 1, now_x))
            {
                v_visit.emplace_back(now_y - 1, now_x);
                ret += recursion(now_y - 1, now_x, n_move + 1);
                v_visit.pop_back();
            }
        }
        
        return ret;
    }
}


void solution()
{
    cin >> N;
    v_visit.emplace_back(start_y, start_x);
    v_visit.emplace_back(start_y - 1, start_x);
    cout << recursion(start_y - 1, start_x, 0);
}

int main(void)
{
    solution();
}