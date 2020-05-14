#include <iostream>
#include <cstring>
using namespace std;

// 0 : �������а�, 1 : �����, 2 : �̷���, 3 : �ž��, 4 : ������, 5 : �Ѱ�������, 6 : �л�ȸ��, 7 : �������а�
// map[i][j] : i���� j�� �� �� ������ 0, ������ 1
long long map[8][8] = { {0, 1, 1, 0, 0, 0, 0, 0},
						{1, 0, 1, 1, 0, 0, 0, 0},
						{1, 1, 0, 1, 0, 1, 0, 0},
						{0, 1, 1, 0, 1, 1, 0, 0},
						{0, 0, 0, 1, 0, 1, 1, 0},
						{0, 0, 1, 1, 1, 0, 0, 1},
						{0, 0, 0, 0, 1, 0, 0, 1},
						{0, 0, 0, 0, 0, 1, 1, 0}
};

long long defaults[30][8][8];
long long two_count[30];

void multiple(long long a[8][8], long long b[8][8], long long c[8][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				c[i][j] += a[i][k] * b[k][j];
				c[i][j] %= 1000000007;
			}
		}
	}
}

void multiple2(long long a[8][8], long long b[8], long long c[8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			c[i] += a[i][j] * b[j];
			c[i] % 1000000007;
		}
	}
}

void copy(long long B[8][8], long long C[8][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			B[i][j] = C[i][j];
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int D;
	cin >> D;

	// A*A*...*A*B���� ���� ������� {0,0}�� ���� �ȴ�.
	// A�� D�� ���ϰ� B�� ����

	long long B[8][8] = { 0, };
	long long C[8][8] = { 0, };
	long long CC[8][8] = { 0, };

	multiple(map, map, C);

	copy(defaults[0], map);	// 1��
	copy(defaults[1], C);	// 2��
	copy(B, C);
	two_count[0] = 1;
	two_count[1] = 2;
	for (int i = 2; i < 30; i++) {
		two_count[i] = two_count[i - 1] * 2;
		memset(C, 0, sizeof(C));
		multiple(B, B, C);
		copy(defaults[i], C);
		copy(B, C);
	}

	/*
	for (int p = 0; p < 20; p++) {
		cout << p << " start" << endl;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cout << defaults[p][i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	*/
	long long F[8][8] = {	{1, 0, 0, 0, 0, 0, 0, 0},
							{0, 1, 0, 0, 0, 0, 0, 0},
							{0, 0, 1, 0, 0, 0, 0, 0},
							{0, 0, 0, 1, 0, 0, 0, 0},
							{0, 0, 0, 0, 1, 0, 0, 0},
							{0, 0, 0, 0, 0, 1, 0, 0},
							{0, 0, 0, 0, 0, 0, 1, 0},
							{0, 0, 0, 0, 0, 0, 0, 1}
	};

	long long G[8][8] = { 0, };
	while (D != 0) {
		// �ڿ������� ����
		for (int i = 29; i > -1; i--) {
			if (D >= two_count[i]) {
				D = D - two_count[i];
	//			cout << D << " " << i << endl;
				multiple(defaults[i], F, G);
				copy(F, G);
				memset(G, 0, sizeof(G));
			}
		}
	}
	/*
	cout << "F" << " start" << endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << F[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	*/
	cout << F[0][0];
	return 0;
}