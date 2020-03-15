/*
E
Problem Statement
Takahashi has a string S of length N consisting of digits from 0 through 9.

He loves the prime number P. He wants to know how many non-empty (contiguous) substrings of S - there are N×(N+1/2) of them - are divisible by Pwhen regarded as integers written in base ten.

Here substrings starting with a 0 also count, and substrings originated from different positions in S are distinguished, even if they are equal as strings or integers.

Compute this count to help Takahashi.

문제 명세서
타카하시에는 0부터 9까지의 숫자로 구성된 길이 N의 문자열 S가 있다.

그는 P를 제일 좋아한다. 그는 S의 비어 있지 않은(연속적인) 하위 문자열이 얼마나 많은지 알고 싶어하는데, 그 중 N×(N+1/2)가 10에 쓰여진 정수로 간주될 때 P에 의해 분할된다.

여기서 0으로 시작하는 하위 문자열도 계수하며, S에서 서로 다른 위치에서 유래한 하위 문자열도 문자열이나 정수로 동일하더라도 구별된다.

이 카운트를 계산하여 타카하시를 돕는다.
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