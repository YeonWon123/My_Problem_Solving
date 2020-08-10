#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX(A,B,C) ((A>B?A:B)>C?(A>B?A:B):C)


// dp[i][j][k][n] : n번째 상태에서, 주사위 값이 (i,j,k)일 때 최적의 기댓값
// dp[1~6][i][j][n-1]의 기댓값의 평균을 구한 뒤, (i,j,k)일 때의 값과 비교한다.
// 둘 중 더 큰 값을 dp[i][j][k][n]에 저장한 뒤, 마지막 단계에서의 값들의 평균을 출력하면 된다.
int n;
long double dp[7][7][7][1001];

int cost(int a, int b, int c) {
    if (a == b && b == c) return 10000 + a * 1000;
    else if (a == b && b != c) return 1000 + a * 100;
    else if (a == c && a != b) return 1000 + a * 100;
    else if (b == c && a != b) return 1000 + b * 100;
    else return MAX(a, b, c) * 100;
}

int main()
{
    scanf("%d", &n);
    // 세번째까지는 기본값으로 초기화 ( O(6^3) )
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= 6; k++) {
                dp[i][j][k][3] = cost(i, j, k);
            }
        }
    }
    // 네번째부터 비교 시작
    for (int l = 4; l <= n; l++) {              
        for (int i = 1; i <= 6; i++) {       
            for (int j = 1; j <= 6; j++) {      
                for (int k = 1; k <= 6; k++) {
                    double sum = 0;

                    for (int m = 1; m <= 6; m++) {
                        sum += dp[m][i][j][l - 1];
                    }

                    if (sum > cost(i, j, k) * 6) { 
                        dp[i][j][k][l] = sum / 6;
                    }
                    else { // 새로 시작
                        dp[i][j][k][l] = cost(i, j, k);
                    }

                }
            }
        }
    }

    double ssum = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= 6; k++) {
                ssum += dp[i][j][k][n];
            }
        }
    }
    printf("%.12lf", ssum / 216.0); // 최종 값을 출력할때는 /(6*6*6)을 한 값이 답이 됨
}
