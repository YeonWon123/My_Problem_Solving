#include <iostream>
#include <cstring>
using namespace std;

int T;
int K;
//int coin[10001];   //coin[i]는 동전 i원의 개수
int p[100];
int n[100];
long long sum[10001];   //sum[i]는 i원을 만드는 개수
int max_cost = -1;   //가진 동전 중 가장 금액이 큰 동전의 금액

//void calc()
//{
//   for (int i = 1; i <= max_cost; i++) {
//      int num = coin[i];
//      if (num == 0) { continue; }
//      for (int j = 10000; j > 0; j--) {
//         for (int k = 1; k <= num; k++) {
//            int index = j - i * k;
//            if (index >= 0) {
//               sum[j] += sum[index];
//            }
//         }
//      }
//   }
//}
void calc()
{
    for (int i = 0; i < K; i++) {
        //if (n[i] == 0) { continue; }
        for (int j = 10000; j > 0; j--) {
            for (int k = 1; k <= n[i]; k++) {
                int index = j - p[i] * k;
                if (index >= 0) {
                    sum[j] += sum[index];
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //memset(coin, 0, sizeof(coin));
    memset(sum, 0, sizeof(sum));
    cin >> T;
    cin >> K;
    for (int i = 0; i < K; i++) {
        /*int x, y;
        cin >> x >> y;
        coin[x] += y;
        if (x > max_cost) { max_cost = x; }*/
        cin >> p[i] >> n[i];
    }
    sum[0] = 1;
    calc();
    cout << sum[T];
}