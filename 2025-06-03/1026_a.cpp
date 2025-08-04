#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void solve() {
    int x; cin >> x;
    int a = 0; int b = 0; int c = 0;
    int cnt = 0;
    while (true) {
        int new_c = min(b*2+1, x);
        if (new_c == c) {
            cout << cnt << endl;
            return;
        }
        c = new_c;
        swap(a, c);
        swap(b, c);
        cnt++;
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