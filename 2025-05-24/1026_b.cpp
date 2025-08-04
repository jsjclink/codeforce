#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    string s; cin >> s;
    int open_count = 0;
    int bundle_count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            open_count++;
        } else {
            open_count--;
        }
        if (open_count == 0) {
            bundle_count++;
        }
    }

    if (bundle_count == 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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