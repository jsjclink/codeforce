#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

void solve() {
    int n; cin >> n;
    int sum = 0;
    int zero_cnt = 0;
    int one_cnt = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a == 0) {
            zero_cnt++;
            continue;
        }
        if (a == 1) {
            one_cnt++;
            continue;
        }
        sum += a;
    }
    while (zero_cnt > 0 && one_cnt > 0) {
        zero_cnt--;
        one_cnt--;
        sum += 2;
    }
    sum += one_cnt;
    sum += zero_cnt;

    cout << sum << endl;
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