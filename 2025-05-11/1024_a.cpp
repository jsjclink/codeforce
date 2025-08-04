#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n, m, p, q; cin >> n >> m >> p >> q;
    int rem = m - (n/p)*q;
    if (rem <= q) {
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