#include <iostream>
using namespace std;

int N, M, K, R;
string name[100];
string target[200];
int pos[200];
int arr1[100][100] = { 0 };
int arr2[100][100] = { 0 };
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> R;
	for (int i = 0; i < N; i++) {
		cin >> name[i];
	}

	cin >> M;
	for (int i = 0; i < N; i++) {
		cin >> target[i];
	}

	cin >> K;
	for (int i = 0; i < K; i++) {

	}

}