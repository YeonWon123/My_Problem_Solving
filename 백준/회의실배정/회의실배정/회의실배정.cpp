/*
1. 끝나는 시간이 빠른 순서대로 정렬
2. 끝나는 시간이 같으면, don't care..? 
-> No! 시작 시간이 빠른 순서대로 정렬

< 반례 >
2
4 4 
1 4
정답 : 2, 오답 : 1

3. 끝나는 시간이 가장 빠른 걸 고른다.
4. 끝나는 시간을 기준으로 고를 수 있는 것들 중에서,
   가장 빠른 것을 고른다.
5. 4번을 반복
*/

#include <iostream>
#include <algorithm>

using namespace std;

int N, result = 1; // 1이상 10만 이하
pair<int, int> meeting[100000]; // 회의 번호, 회의 시점, 종점

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