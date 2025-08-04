#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int fib[12] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};


void solve() {
    int n, m; cin >> n >> m;
    string ans = "";
    for (int i = 0; i < m; i++) {
        int w, l, h; cin >> w >> l >> h;

        if (fib[n] <= w && fib[n] <= l && fib[n] <= h) {
            if (fib[n+1] <= w || fib[n+1] <= l || fib[n+1] <= h) {
                ans += "1";
            } else {
                ans += "0";
            }
        } else {
            ans += "0";
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}