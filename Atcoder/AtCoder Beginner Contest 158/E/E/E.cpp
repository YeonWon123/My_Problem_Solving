/*
E
Problem Statement
Takahashi has a string S of length N consisting of digits from 0 through 9.

He loves the prime number P. He wants to know how many non-empty (contiguous) substrings of S - there are N��(N+1/2) of them - are divisible by Pwhen regarded as integers written in base ten.

Here substrings starting with a 0 also count, and substrings originated from different positions in S are distinguished, even if they are equal as strings or integers.

Compute this count to help Takahashi.

���� ����
Ÿī�Ͻÿ��� 0���� 9������ ���ڷ� ������ ���� N�� ���ڿ� S�� �ִ�.

�״� P�� ���� �����Ѵ�. �״� S�� ��� ���� ����(��������) ���� ���ڿ��� �󸶳� ������ �˰� �;��ϴµ�, �� �� N��(N+1/2)�� 10�� ������ ������ ���ֵ� �� P�� ���� ���ҵȴ�.

���⼭ 0���� �����ϴ� ���� ���ڿ��� ����ϸ�, S���� ���� �ٸ� ��ġ���� ������ ���� ���ڿ��� ���ڿ��̳� ������ �����ϴ��� �����ȴ�.

�� ī��Ʈ�� ����Ͽ� Ÿī�Ͻø� ���´�.
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, P;
char S[200001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> P >> S;

	

	return 0;
}