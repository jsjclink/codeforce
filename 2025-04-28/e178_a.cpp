#include <iostream>

using namespace std;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    if ((c-2*b+a >= 0) && ((c-2*b+a)%3 == 0)) {
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