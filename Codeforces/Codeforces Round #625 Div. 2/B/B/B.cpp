#include <iostream>
#include <vector>
using namespace std;

typedef struct POINT {
	int last_value;
	int last_pos;
	long long sum;
} point;

point result[200000];
int counts = 0;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int temp;
	int sw = 0;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		sw = 0;
		for (int j = 0; j < counts; j++) {
			if ((i - result[j].last_pos) == (temp - result[j].last_value)) {
				sw = 1;
				result[j].last_pos = i;
				result[j].last_value = temp;
				result[j].sum += temp;
				break;
			}
		}

		if (sw == 0) {
			result[counts].last_pos = i;
			result[counts].last_value = temp;
			result[counts].sum += temp;
			counts++;
		}
	}

	// counts 중에서 가장 큰 거를 고르면 됨
	long long answer = 0;
	for (int i = 0; i < counts; i++) {
		if (answer < result[i].sum)
			answer = result[i].sum;
	}

	cout << answer;
	return 0;
}