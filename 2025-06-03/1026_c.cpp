#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;


void solve() {
    int n; cin >> n;
    vector<long long> a_list(n);
    for (int i = 0; i < n; i++) {
        cin >> a_list[i];
    }
    
    vector<long long> diff_num_left(n);
    for (int i = 0; i < n; i++) {
        if (i > 0 && a_list[i] == a_list[i-1]) {
            diff_num_left[i] = diff_num_left[i-1];
        } else {
            diff_num_left[i] = i;
        }
    }
    vector<long long> diff_num_right(n);
    for (int i = n-1; i >= 0; i--) {
        if (i < n-1 && a_list[i] == a_list[i+1]) {
            diff_num_right[i] = diff_num_right[i+1];
        } else {
            diff_num_right[i] = n-1-i;
        }
    }

    long long min_cost = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        long long cost = (diff_num_left[i] + diff_num_right[i]) * a_list[i];
        min_cost = min(min_cost, cost);
    }
    cout << min_cost << endl;
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