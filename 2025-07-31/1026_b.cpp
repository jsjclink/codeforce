#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

void solve() {
    int n, s; cin >> n >> s;
    int sum = 0;
    int zero_cnt = 0, one_cnt = 0, two_cnt = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        sum += a;
        if (a == 0) zero_cnt++;
        else if (a == 1) one_cnt++;
        else two_cnt++;
    }

    if (s - sum >= 2 || s == sum) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < zero_cnt; i++) cout << 0 << " ";
        for (int i = 0; i < two_cnt; i++) cout << 2 << " ";
        for (int i = 0; i < one_cnt; i++) cout << 1 << " ";
        cout << endl;
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