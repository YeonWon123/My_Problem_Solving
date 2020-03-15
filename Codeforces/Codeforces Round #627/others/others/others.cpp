#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1234567;
int n;
int a[N];

void solve() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        int res = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 != mx % 2) {
                res = 0;
                break;
            }
        }
        if (res) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    solve();
    return 0;
}
