#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n; cin >> n;
    int a_list[n];

    for (int i = 0; i < n; i++) {
        cin >> a_list[i];
    }
    sort(a_list, a_list+n);
    if (a_list[0] % 2 == a_list[n-1] % 2) {
        cout << 0 << endl;
        return;
    }

    for (int i = 1; i < n; i++) {
        if (a_list[i] % 2 != a_list[0] % 2) {
            cout << i << endl;
            return;
        }
        if (a_list[n-1-i] % 2 != a_list[n-1] % 2) {
            cout << i << endl;
            return;
        }
    }

    cout << n-1 << endl;
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