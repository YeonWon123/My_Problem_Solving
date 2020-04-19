/*
1. ������ �ð��� ���� ������� ����
2. ������ �ð��� ������, don't care..? 
-> No! ���� �ð��� ���� ������� ����

< �ݷ� >
2
4 4 
1 4
���� : 2, ���� : 1

3. ������ �ð��� ���� ���� �� ����.
4. ������ �ð��� �������� �� �� �ִ� �͵� �߿���,
   ���� ���� ���� ����.
5. 4���� �ݺ�
*/

#include <iostream>
#include <algorithm>

using namespace std;

int N, result = 1; // 1�̻� 10�� ����
pair<int, int> meeting[100000]; // ȸ�� ��ȣ, ȸ�� ����, ����

bool myCompare(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> meeting[i].first >> meeting[i].second;
    }
    sort(meeting, meeting + N, myCompare);
    int base = meeting[0].second;
    for (int i = 1; i < N; i++)
    {
        if (meeting[i].first >= base)
        {
            base = meeting[i].second;
            ++result;
        }
    }
    cout << result;
    return 0;
}