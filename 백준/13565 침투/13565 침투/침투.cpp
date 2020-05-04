#include <iostream>
using namespace std;

// 2차원 M, N 격자는 전역변수로 선언(크기가 너무 커질수 있음)
char** map;

void calculate(int x, int y, int M, int N);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	cin >> M >> N;

	// 2차원 동적 할당
	map = new char* [M];
	for (int i = 0; i < M; i++)
		map[i] = new char[N];

	// 공백 없이 0과 1을 입력받아야 하므로 char형 2차원 배열 사용
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++)
		calculate(0, i, M, N);
	
	cout << "NO";
	return 0;
}

void calculate(int x, int y, int M, int N)
{
	if (x < 0 || y < 0 || y >= N)
		return; // 함수 종료

	if (map[x][y] == '0')
	{
		map[x][y] = '2'; // 한번 탐사한 곳을 2로 한다.
		if (x == M - 1)
		{
			cout << "YES";
			exit(0); // 프로그램 종료
		}
		//cout << "map[" << x << "][" << y << "] 탐색!" << endl;
		calculate(x + 1, y, M, N);
		calculate(x, y + 1, M, N);
		calculate(x - 1, y, M, N);
		calculate(x, y - 1, M, N);
	}
}

/*
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int map[1000][1000];	//map[y][x]
int n, m;	//n=y, m=x
int dirX[4] = { -1,0,1,0 };
int dirY[4] = { 0,1,0, -1 };
int visited[1000][1000];

bool func(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= m) { return false; }
	if (map[y][x] != 0) { return false; }
	if (y == (n - 1)) { return true; }
	if (visited[y][x] != 0) { return false; }
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		if (func(y + dirY[i], x + dirX[i])) {
			return true;
		}
	}
	return false;
}

int main()
{
	string input;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int j = 0; j < m; j++) {
			map[i][j] = input[j] - '0';
		}
	}
	for (int i = 0; i < m; i++) {
		if (map[0][i] == 0) {
		//	memset(visited, 0, sizeof(visited));
			if (func(0, i)) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}
*/