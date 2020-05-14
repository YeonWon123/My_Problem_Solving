// Coding by ������, 20150413
// ��Ʈ���� ��İ��� �˰��� ���� (������� : C++)

#include <iostream>
#include <iomanip>
using namespace std;

// �⺻���� ��� ������ �ϴ� ǥ�� �˰��� �Լ�
void matrixmult(int n, int** A, int** B, int** C);

// ��Ʈ���� ��� ���� �˰��� �Լ�
void strassen(int n, int** A, int B[8][8], int C[8][8]);

int main()
{
	// �迭�� ũ�⸦ �Է¹޾� ������
	int n = 8;

	// �Է¹��� �迭�� ũ���� �� �迭�� ���� �Ҵ��Ͽ� ����
	// A, B�� n by n ��� �Է��� ���� �迭, C�� A * B ����� ��Ÿ�� �迭
	int A[8][8] = {	  {0, 1, 1, 0, 0, 0, 0, 0},
					  {1, 0, 1, 1, 0, 0, 0, 0},
					  {1, 1, 0, 1, 0, 1, 0, 0},
					  {0, 1, 1, 0, 1, 1, 0, 0},
					  {0, 0, 0, 1, 0, 1, 1, 0},
					  {0, 0, 1, 1, 1, 0, 0, 1},
					  {0, 0, 0, 0, 1, 0, 0, 1},
					  {0, 0, 0, 0, 0, 1, 1, 0}
	};

	int** A = new int* [8];
	for (int i = 0; i < n; i++)
		A[i] = new int[8];

	int** B = new int* [8];
	for (int i = 0; i < n; i++)
		B[i] = new int[8];

	int** C = new int* [n];
	for (int i = 0; i < n; i++)
		C[i] = new int[n];

	strassen(n, A, B, C);

	cout.setf(ios::right);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(5) << C[i][j] << " ";
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "C[" << i << "][" << j << "] = " << C[i][j] << endl;
		}
	}

	return 0;
}

// Algorithm 2.8 Strassen
// ���� : n�� 2�� �ŵ������� �� 2���� n*n ����� ���� ���Ͻÿ�.
// �Է� : 2�� �ŵ������� ���� n, 2���� n*n ��� A�� B
// ��� : A�� B�� �� C
void strassen(int n, int** A, int** B, int** C)
{
	// cout << "strassen ���� ����!!!" << endl;
	if (n <= 2) {
		// ǥ�� �˰������� C = A * B�� ����Ѵ�.
		matrixmult(n, A, B, C);
	}
	else {
		// A�� A_11, A_12, A_13, A_14�� �����Ѵ�.

		// int A11[n / 2][n / 2]; �κ��� �����Ҵ����� ����
		int** A11 = new int* [n / 2];
		for (int i = 0; i < n / 2; i++)
			A11[i] = new int[n / 2];

		// int A12[n / 2][n / 2]; �κ��� �����Ҵ����� ����
		int** A12 = new int* [n / 2];
		for (int i = 0; i < n / 2; i++)
			A12[i] = new int[n / 2];

		// int A21[n / 2][n / 2]; �κ��� �����Ҵ����� ����
		int** A21 = new int* [n / 2];
		for (int i = 0; i < n / 2; i++)
			A21[i] = new int[n / 2];

		// int A22[n / 2][n / 2]; �κ��� �����Ҵ����� ����
		int** A22 = new int* [n / 2];
		for (int i = 0; i < n / 2; i++)
			A22[i] = new int[n / 2];

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				A11[i][j] = A[i][j];
				A12[i][j] = A[i][j + n / 2];
				A21[i][j] = A[i + n / 2][j];
				A22[i][j] = A[i + n / 2][j + n / 2];
			}
		}


		// Ȯ�ο� �ڵ�
		/*
			for (int i = 0; i < n/2; i++) {
				cout << endl;
				for (int j = 0; j < n/2; j++)
					cout << "A11[" << i << "][" << j << "] ="
					<< A11[i][j] << " " << endl;
			}

			for (int i = 0; i < n / 2; i++) {
				cout << endl;
				for (int j = 0; j < n / 2; j++)
					cout << "A12[" << i << "][" << j << "] ="
					<< A12[i][j] << " " << endl;
			}

			for (int i = 0; i < n / 2; i++) {
				cout << endl;
				for (int j = 0; j < n / 2; j++)
					cout << "A21[" << i << "][" << j << "] ="
					<< A21[i][j] << " " << endl;
			}

			for (int i = 0; i < n / 2; i++) {
				cout << endl;
				for (int j = 0; j < n / 2; j++)
					cout << "A22[" << i << "][" << j << "] ="
					<< A22[i][j] << " " << endl;
			}
		*/

		// B�� B_11, B_12, B_13, B_14�� �����Ѵ�.
		// int B11[n / 2][n / 2]; �κ��� �����Ҵ����� ����
		int** B11 = new int* [n / 2];
		for (int i = 0; i < n / 2; i++)
			B11[i] = new int[n / 2];

		// int B12[n / 2][n / 2]; �κ��� �����Ҵ����� ����
		int** B12 = new int* [n / 2];
		for (int i = 0; i < n / 2; i++)
			B12[i] = new int[n / 2];

		// int B21[n / 2][n / 2]; �κ��� �����Ҵ����� ����
		int** B21 = new int* [n / 2];
		for (int i = 0; i < n / 2; i++)
			B21[i] = new int[n / 2];

		// int B22[n / 2][n / 2]; �κ��� �����Ҵ����� ����
		int** B22 = new int* [n / 2];
		for (int i = 0; i < n / 2; i++)
			B22[i] = new int[n / 2];

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				B11[i][j] = B[i][j];
				B12[i][j] = B[i][j + n / 2];
				B21[i][j] = B[i + n / 2][j];
				B22[i][j] = B[i + n / 2][j + n / 2];
			}
		}
		// Ȯ�ο� �ڵ�
		/*
		for (int i = 0; i < n / 2; i++) {
			cout << endl;
			for (int j = 0; j < n / 2; j++)
				cout << "B11[" << i << "][" << j << "] ="
				<< B11[i][j] << " " << endl;
		}

		for (int i = 0; i < n / 2; i++) {
			cout << endl;
			for (int j = 0; j < n / 2; j++)
				cout << "B12[" << i << "][" << j << "] ="
				<< B12[i][j] << " " << endl;
		}

		for (int i = 0; i < n / 2; i++) {
			cout << endl;
			for (int j = 0; j < n / 2; j++)
				cout << "B21[" << i << "][" << j << "] ="
				<< B21[i][j] << " " << endl;
		}

		for (int i = 0; i < n / 2; i++) {
			cout << endl;
			for (int j = 0; j < n / 2; j++)
				cout << "B22[" << i << "][" << j << "] ="
				<< B22[i][j] << " " << endl;
		}
		*/

		// ��Ʈ���� ������� C = A*B�� ����ϱ�
		// 1. M1���� M7���� ���� ����.

		// int temp1[n / 2][n / 2]; �κ��� �����Ҵ����� ����
		int** temp1 = new int* [n / 2];
		for (int i = 0; i < n / 2; i++)
			temp1[i] = new int[n / 2];

		// int temp2[n / 2][n / 2]; �κ��� �����Ҵ����� ����
		int** temp2 = new int* [n / 2];
		for (int i = 0; i < n / 2; i++)
			temp2[i] = new int[n / 2];

		// M1 = (A11 + A22) * (B11 + B22)

		// int M1[n / 2][n / 2]; �κ��� �����Ҵ����� ����
		int** M1 = new int* [n / 2];
		for (int i = 0; i < n / 2; i++)
			M1[i] = new int[n / 2];

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				temp1[i][j] = A11[i][j] + A22[i][j];
				temp2[i][j] = B11[i][j] + B22[i][j];
			}
		}

		/*
		//Ȯ�ο� �ڵ�
		for (int i = 0; i < n / 2; i++) {
			cout << endl;
			for (int j = 0; j < n / 2; j++)
				cout << "temp1[" << i << "][" << j << "] ="
				<< temp1[i][j] << " " << endl;
		}

		for (int i = 0; i < n / 2; i++) {
			cout << endl;
			for (int j = 0; j < n / 2; j++)
				cout << "temp2[" << i << "][" << j << "] ="
				<< temp2[i][j] << " " << endl;
		}
		*/
		strassen(n / 2, temp1, temp2, M1);


		// M2 = (A21 + A22) * B11

		// int M2[n / 2][n / 2]; �κ��� �����Ҵ����� ����
		int** M2 = new int* [n / 2];
		for (int i = 0; i < n / 2; i++)
			M2[i] = new int[n / 2];

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				temp1[i][j] = A21[i][j] + A22[i][j];
			}
		}


		strassen(n / 2, temp1, B11, M2);

		/*
		// Ȯ��
		cout << "m2" << endl;
		for (int i = 0; i < n / 2; i++) {
			cout << endl;
			for (int j = 0; j < n / 2; j++)
				cout << "[" << i << "][" << j << "] ="
				<< M2[i][j] << " " << endl;
		}
		*/

		// M3 = A11 * (B12 - B22)

		// int M3[n / 2][n / 2]; �κ��� �����Ҵ����� ����
		int** M3 = new int* [n / 2];
		for (int i = 0; i < n / 2; i++)
			M3[i] = new int[n / 2];

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				temp1[i][j] = B12[i][j] - B22[i][j];
			}
		}
		strassen(n / 2, A11, temp1, M3);

		/*
		// Ȯ��
		cout << "m3" << endl;
		for (int i = 0; i < n / 2; i++) {
			cout << endl;
			for (int j = 0; j < n / 2; j++)
				cout << "temp1[" << i << "][" << j << "] ="
				<< M3[i][j] << " " << endl;
		}
		*/

		// M4 = A22 * (B21 - B11)

		// int M4[n / 2][n / 2]; �κ��� �����Ҵ����� ����
		int** M4 = new int* [n / 2];
		for (int i = 0; i < n / 2; i++)
			M4[i] = new int[n / 2];

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				temp1[i][j] = B21[i][j] - B11[i][j];
			}
		}



		strassen(n / 2, A22, temp1, M4);

		/*
		// Ȯ��
		cout << "m4" << endl;
		for (int i = 0; i < n / 2; i++) {
			cout << endl;
			for (int j = 0; j < n / 2; j++)
				cout << "temp1[" << i << "][" << j << "] ="
				<< M4[i][j] << " " << endl;
		}
		*/

		//M5 = (A11 + A12) * B22

		// int M5[n / 2][n / 2]; �κ��� �����Ҵ����� ����
		int** M5 = new int* [n / 2];
		for (int i = 0; i < n / 2; i++)
			M5[i] = new int[n / 2];

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				temp1[i][j] = A11[i][j] + A12[i][j];
			}
		}
		strassen(n / 2, temp1, B22, M5);

		/*
		// Ȯ��
		cout << "m5" << endl;
		for (int i = 0; i < n / 2; i++) {
			cout << endl;
			for (int j = 0; j < n / 2; j++)
				cout << "temp1[" << i << "][" << j << "] ="
				<< M5[i][j] << " " << endl;
		}
		*/

		// M6 = (A21 - A11) * (B11 + B12)

		// int M6[n / 2][n / 2]; �κ��� �����Ҵ����� ����
		int** M6 = new int* [n / 2];
		for (int i = 0; i < n / 2; i++)
			M6[i] = new int[n / 2];

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				temp1[i][j] = A21[i][j] - A11[i][j];
				temp2[i][j] = B11[i][j] + B12[i][j];
			}
		}
		strassen(n / 2, temp1, temp2, M6);

		/*
		// Ȯ��
		cout << "m6" << endl;
		for (int i = 0; i < n / 2; i++) {
			cout << endl;
			for (int j = 0; j < n / 2; j++)
				cout << "temp1[" << i << "][" << j << "] ="
				<< M6[i][j] << " " << endl;
		}
		*/

		// M7 = (A12 - A22) * (B21 + B22)

		// int M7[n / 2][n / 2]; �κ��� �����Ҵ����� ����
		int** M7 = new int* [n / 2];
		for (int i = 0; i < n / 2; i++)
			M7[i] = new int[n / 2];

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				temp1[i][j] = A12[i][j] - A22[i][j];
				temp2[i][j] = B21[i][j] + B22[i][j];
			}
		}
		strassen(n / 2, temp1, temp2, M7);

		/*
		// Ȯ��
		cout << "m7" << endl;
		for (int i = 0; i < n / 2; i++) {
			cout << endl;
			for (int j = 0; j < n / 2; j++)
				cout << "temp1[" << i << "][" << j << "] ="
				<< M7[i][j] << " " << endl;
		}
		*/

		// ��Ʈ����� ������� C = A*B�� ����Ѵ�.
		// 2. �տ��� ���� M1 ~ M7������ ���� C11, C12, C21, C22�� ���ؼ�,
		//    ��ü ��� C�� �� ��ġ�� ����־ ����� C�� �ϼ��Ѵ�.

		// C11 = M1 + M4 - M5 + M7
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
			}
		}


		// C12 = M3 + M5
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				C[i][j + 2] = M3[i][j] + M5[i][j];
			}
		}


		// C21 = M2 + M4
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				C[i + 2][j] = M2[i][j] + M4[i][j];
			}
		}

		// C22 = M1 + M3 - M2 + M6
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				C[i + 2][j + 2] = M1[i][j] + M3[i][j] - M2[i][j] + M6[i][j];
			}
		}

		/*
		// Ȯ�ο� �ڵ�
		for (int i = 0; i < n / 2; i++) {
			cout << endl;
			for (int j = 0; j < n / 2; j++)
				cout << "C11[" << i << "][" << j << "] ="
				<< C[i][j] << " " << endl;
		}

		// Ȯ�ο� �ڵ�
		for (int i = 0; i < n / 2; i++) {
			cout << endl;
			for (int j = 0; j < n / 2; j++)
				cout << "C12[" << i << "][" << j << "] ="
				<< C[i][j + n / 2] << " " << endl;
		}

		// Ȯ�ο� �ڵ�
		for (int i = 0; i < n / 2; i++) {
			cout << endl;
			for (int j = 0; j < n / 2; j++)
				cout << "C21[" << i << "][" << j << "] ="
				<< C[i + n / 2][j] << " " << endl;
		}

		// Ȯ�ο� �ڵ�
		for (int i = 0; i < n / 2; i++) {
			cout << endl;
			for (int j = 0; j < n / 2; j++)
				cout << "C22[" << i << "][" << j << "] ="
				<< C[i + n / 2][j + n / 2] << " " << endl;
		}
		*/

	}

	// cout << "strassen ��!!!" << endl;
}

// �⺻���� ��� ������ �ϴ� ǥ�� �˰��� �Լ�
// ��, 2*2 ����� ǥ�� �˰������� ���ϴ� �Լ�, ���� n�� 2 ������ �����̾�� �Ѵ�.
void matrixmult(int n, int** A, int** B, int** C)
{
	// cout << "matrixmult ����!!" << endl;
	int i, j, k;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = 0;
			for (k = 0; k < n; k++) {
				C[i][j] = C[i][j] + A[i][k] * B[k][j]; // ���� ����
			}
		}
	}
	/*
	// Ȯ�ο� �ڵ�
		for (int i = 0; i < n; i++) {
			cout << endl;
			for (int j = 0; j < n; j++)
				cout << "C[" << i << "][" << j << "] ="
				<< C[i][j] << " " << endl;
		}
	*/
}