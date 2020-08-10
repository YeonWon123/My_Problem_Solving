



/*

B번 던전지도.

N행 M열 격자 형태 방

아래쪽에서 i번째 행의 왼쪽에서 j번쨰 방 i, j
던전 각 방엔 R, U
임의의 방에서 시작
이번에 깬 방이 i, j일때 R이 적혀있다면 i, j + 1이동
U라면 i + 1, j 이동

던전 지도를 만드는 규칙
1. 지도의 한행을 구성하는 K종류의 블록을 미리 만들고 각 블록에 알파벳 대문자의 처음 K글자중 하나 대응.
      각 블록은 R과 U로만 이루어진 길이 M의 문자열이다.
2. 알파벳 대문자의 처음 K종류로 이루어진 길이 N의 문자열을 생성 후, i번째 글자에 대응되는 블록으로 던전의 아래에서 i번째 행을 만든다.

던전 가장 오른쪽 위 N, M 보스방 -> 막대한 보상
   시작 위치에 따라 도달 불가능할수도.

현재 지도에서 보스 방에 도달 가능한 시작 방이 몇개일까?

1. 이해
   입력:
      던전 행 N
      열 M
      블록 종류 K

      K개의 줄에 R또는 U로 이루어진 길이 M의 문자열 주어짐.
      i번째 줄은 i번째 알파벳 대문자에 대응.

      알파벳 대문자의 처음 K종류로 이루어진 길이 N의 문자열 주어짐.
      j번째 글자는 던전의 아래에서 j번째 행을 구성하는 블록을 의미한다.

   출력:
      (N, M)에 도달할 수 있는 시작 방의 개수를 출력한다.
      주의) 이 방도 시작방이 될 수 있다

2. 재구성
   N행 M열의 공간에서
   각 위치에 적힌 지시에 따라 이동.
   가장 우측 상단에 도달할 수 있는 위치의 수는?

*/



// #include <bits/stdc++.h>

#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<queue>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int N; // 행 
int M; // 열 
int K; // 블록의 종류, 필요 없음?
string hang;
string last_str;

enum Dir {
    R,
    U,
};

// 좌측, 하단 순서.
int dir_x[2] = { -1, 0 }; // 왼쪽으로
int dir_y[2] = { 0, 1 }; // 아래로

typedef struct _pos {
    int y, x;
}Pos;


vector<string> jido; // jido[i][j] i번째 알파뱃(0부터 시작)행의 정보
vector<vector<bool>> maps; // 현재 방의 지시. R = 0 U = 1. maps[y][x] -> y행 x열. 왼쪽 위가 0, 0

long long min_x, max_x; // 현재 보는 행에서 유망한 원소의 가장 좌측값, 우측값.

long long ans;


void travel() {
    // 시작 -> 우측 상단. y = 0, x = M - 1
    // 왼쪽으로 쭉 본다. 시작 지점은 max_x = x, U를 만날때까지 min_x-- 갱신.
    // min_x부터 max_x까지 잡고 각원소에 도착할 수 있는 아래 원소들을 찾는다.
    // 이 원소들은 반드시 
    // 아래 원소들중 가장 우측 원소가 mmax_x이고, 이 원소들중 제일 왼쪽 친구에서 왼쪽으로 쭉 보면서 min_x-- 갱신
    // 아래 행이 없을 때까지 반복한다.

    Pos now = { 0, M - 1 }; // 우측 상단에서 시작한다. y행 x열
    bool type;
    max_x = now.x; // 초기값
    min_x = now.x;
    bool exist = true;
    for (int n = 0; n < N; n++) // 제일 윗행 부터 마지막행 까지 본다.
    {
        //printf("(%d, %d ~ %d): %d\n", n, min_x, max_x, ans);
        if (exist == false) // 현재 행이 없으면 아래 과정 ㄴㄴ .
            break;

        for (int i = min_x - 1; i >= 0; --i) // 제일 작은 친구의 왼쪽 친구부터 왼쪽으로 쭉 본다. 단 제일 왼쪽 친구는 그 오른쪽을 볼 필요 없다.
        {
            type = maps[n][i];
            if (type == U) // U를 만나면 더이상 볼 필요 없다.
                break;
            else {
                min_x--;
            }
        }

        ans += max_x - min_x + 1; // 현재 행에서 유효한 원소의 수를 추가한다.


        if (n >= N - 1) // 마지막 행은  안봐도 됨
            break;
        // 이 친구들에게 직접 도달 가능한 아래쪽 원소들 중 제일 오른쪽과 제일 왼쪽을 구한다. 그 사이는 전부 윗행에 도달 가능.

        // 제일 왼쪽 찾기
        exist = false; // 다음 행에서 현재 행으로 올 수 있는게 존재하는지
        for (int i = min_x - 1; i >= 0; i--)
        {
            type = maps[n + 1][i]; // 아래 원소의 타입
            if (type == U) { // 이거면 됨
                min_x = i;
                exist = true;
                break;
            }
        }
        // 제일 오른쪽 찾기
        for (int i = max_x; i >= min_x; i--)
        {
            type = maps[n + 1][i]; // 아래 원소의 타입
            if (type == U) { // 이거면 됨
                max_x = i;
                exist = true;
                break;
            }
        }
    }

}

void solve() {
    cin >> N >> M >> K;


    jido.reserve(30);
    maps.reserve(200001);

    for (int i = 0; i < N + 2; i++) // 지도 정보를 받는다. 행의 수가 N보다 작을 수 있다. 어떻게 확인하지?
    {
        cin >> hang; // 현재 행을 받아온다.

        if (cin.eof()) { // 받아온 행이 마지막 행이면 이건 거시기임.
            last_str = hang;
            break;
        }
        else {
            jido.push_back(hang);
        }
    }

    for (int i = 0; i < last_str.length(); i++) // 행 알파벳과 알파벳에 해당하는 행 형태로 맵을 작성.
    {
        char now_line = last_str[last_str.length() - i - 1] - 'A'; // 현재 행의 형태를 나타내는 숫자. 아래행부터 주어졌다 -> 거꾸로 보자. 그 정보는? jido[i]에 있다.
        maps.push_back(vector<bool>());
        for (int j = 0; j < jido[now_line].length(); j++)
        {
            maps[i].push_back(jido[now_line][j] == 'R' ? R : U);
        }
    }

    travel();

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}