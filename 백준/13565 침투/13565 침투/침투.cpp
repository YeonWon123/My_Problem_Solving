#include <iostream>
using namespace std;

// 2���� M, N ���ڴ� ���������� ����(ũ�Ⱑ �ʹ� Ŀ���� ����)
char** map;

void calculate(int x, int y, int M, int N);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	cin >> M >> N;

	// 2���� ���� �Ҵ�
	map = new char* [M];
	for (int i = 0; i < M; i++)
		map[i] = new char[N];

	// ���� ���� 0�� 1�� �Է¹޾ƾ� �ϹǷ� char�� 2���� �迭 ���
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
		return; // �Լ� ����

	if (map[x][y] == '0')
	{
		map[x][y] = '2'; // �ѹ� Ž���� ���� 2�� �Ѵ�.
		if (x == M - 1)
		{
			cout << "YES";
			exit(0); // ���α׷� ����
		}
		//cout << "map[" << x << "][" << y << "] Ž��!" << endl;
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