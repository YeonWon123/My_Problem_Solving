#include <iostream>
using namespace std;

char map[100][100];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	char temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp;
			// temp¸¦ ¹Ù²ã¼­
			switch (temp) {
			case '.':
				temp = '.';
				break;
			case 'o':
				temp = 'O';
				break;
			case '-':
				temp = '|';
				break;
			case '|':
				temp = '-';
				break;
			case '/':
				temp = '\\';
				break;
			case '\\':
				temp = '/';
				break;
			case '^':
				temp = '<';
				break;
			case '<':
				temp = 'v';
				break;
			case 'v':
				temp = '>';
				break;
			case '>':
				temp = '^';
				break;
			}
			map[j][i] = temp;
		}
	}

	for (int i = M-1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}