#include <iostream>

using namespace std;

void solve() {
    int n; string ab; cin >> n >> ab;
    bool has_1 = ab[0] == 'A';
    bool has_n = ab[n-1] == 'A';
    bool has_n1 = ab[n-2] == 'A';

    int a_count = 0;
    for (int i = 0; i < n; i++) { 
        if (ab[i] == 'A') {
            a_count += 1;
        }
    }

    if (has_1 && has_n) {
        cout << "Alice" << endl;
    } else if (has_n && has_n1) {
        cout << "Alice" << endl;
    } else if (has_1 && has_n1 && a_count == n-1) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
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