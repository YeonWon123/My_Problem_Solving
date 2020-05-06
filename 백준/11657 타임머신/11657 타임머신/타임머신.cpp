// 정수 overflow가 발생할 수 있기 때문에, long long으로 처리해야 함
// 
#include <cstdio>
#include <vector>
using namespace std;

#define INF 9223372036854775807

int main(void)
{
	int N, M;
	long long dist[6000]; // 크기 주의!
	bool cycle = false;
	vector<pair<int, int>> v[6000]; // 크기 주의! testcase가 있을 경우 전역 변수로 설정!
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int A, B, C;
		scanf("%d%d%d", &A, &B, &C);
		v[A].push_back(make_pair(B, C));
	}
	for (int i = 1; i <= N; i++)
		dist[i] = INF;

	dist[1] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (auto& n : v[j]) {
				if (dist[j] != INF && dist[n.first] > n.second + dist[j]) {
					dist[n.first] = n.second + dist[j];
					if (i == N) cycle = true;
				}
			}
		}
	}

	if (cycle) printf("-1\n");
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF)
				printf("-1\n");
			else
				printf("%d\n", dist[i]);
		}
	}
}