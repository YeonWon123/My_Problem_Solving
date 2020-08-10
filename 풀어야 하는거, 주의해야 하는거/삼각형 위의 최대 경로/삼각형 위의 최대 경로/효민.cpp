#include <iostream>
using namespace std;
int n;
int arr[501];
int pre_max[501];
int post_max[501];
int main()
{
    int res;
    cin >> n;
    if (n == 0) { cout << 0; return 0; }
    cin >> post_max[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> arr[j];
            pre_max[j] = post_max[j];
        }
        post_max[1] = pre_max[1] + arr[1];
        post_max[i] = pre_max[i - 1] + arr[i];
        for (int j = 2; j < i; j++) {
            if (pre_max[j - 1] > pre_max[j]) {
                post_max[j] = pre_max[j - 1] + arr[j];
            }
            else {
                post_max[j] = pre_max[j] + arr[j];
            }
        }

        cout << "post_max" << "\n";
        for (int k = 0; k <= n; k++) {
            cout << post_max[k] << " ";
        }
        cout << "\npre_max\n";
        for (int k = 0; k <= n; k++) {
            cout << pre_max[k] << " ";
        }
        cout << "\n";
    }
    res = post_max[1];
    for (int i = 2; i <= n; i++) {
        if (post_max[i] > res) {
            res = post_max[i];
        }
    }
    cout << res;
}