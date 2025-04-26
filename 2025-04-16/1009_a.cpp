#include <iostream>

using namespace std;

void solve() {
    int l, r, d, u;
    cin >> l >> r >> d >> u;
    if (l == r && r == d && d == u) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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