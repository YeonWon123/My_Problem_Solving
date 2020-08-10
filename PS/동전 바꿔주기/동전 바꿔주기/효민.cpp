#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T;
int k;
int coin[10001];   //coin[i]는 동전 i원의 개수
int sum[10000001];   //sum[i]는 i원을 만드는 개수
int max_cost = -1;   //가진 동전 중 가장 금액이 큰 동전의 금액

void calc()
{
//    int pre_cost = 0;
    for (int i = 1; i <= max_cost; i++) {
        int num = coin[i];
        if (!num) { continue; }
//        pre_cost += i * num;
        for (int j = 10000; j > 0; j--) {
            for (int k = num; k >= 1; k--) {
                int index = j - i * k;
                if (index >= 0) {
                    sum[j] += sum[index];
                }
            }
        }
    }
}

int main()
{
    memset(coin, 0, sizeof(coin));
    memset(sum, 0, sizeof(sum));
    cin >> T;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        coin[x] = y;
        if (x > max_cost) { max_cost = x; }
    }
    sum[0] = 1;
    calc();
    cout << sum[T];
}