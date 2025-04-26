#include <iostream>

using namespace std;

void solve() {
    int x;
    cin >> x;

    int one_pos = -1;
    int zero_pos = -1;
    int i = 0;
    while (x > 1) {
        if (x & 1) {
            one_pos = i;
        } else {
            zero_pos = i;
        }
        x = x >> 1;
        i++;
    }
    if (one_pos != -1 && zero_pos != -1) {
        cout << (1 << one_pos) + (1 << zero_pos) << endl;
    } else {
        cout << -1 << endl;
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