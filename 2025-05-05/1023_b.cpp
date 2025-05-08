#include <iostream>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    int a_min, a_max;
    int a_sum = 0;
    int a_list[n];
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        a_list[i] = a;
        a_sum += a;
        if (i == 0) {
            a_min = a;
            a_max = a;
        } else {
            a_min = min(a_min, a);
            a_max = max(a_max, a);
        }
    }

    int max_count = 0;
    for (int i = 0; i < n; i++) {
        if (a_list[i] == a_max) {
            max_count++;
        }
    }

    if (max_count > 1) {
        if (a_max - a_min > k) {
            cout << "Jerry" << endl;
            return;
        }
    } else {
        if (a_max - 1 - a_min > k) {
            cout << "Jerry" << endl;
            return;
        }
    }

    if (a_sum % 2 == 0) {
        cout << "Jerry" << endl;
    } else {
        cout << "Tom" << endl;
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