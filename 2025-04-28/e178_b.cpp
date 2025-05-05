#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    int n; cin >> n;
    int a_list[n];
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        a_list[i] = a;
    }

    long long suffix_sum[n]; long long cur_sum = 0;
    int prefix_max[n]; int cur_max = 0;
    for (int i = n-1; i >= 0; i--) {
        cur_sum += a_list[i];
        suffix_sum[i] = cur_sum;
    }
    for (int i = 0; i < n; i++) {
        cur_max = max(cur_max, a_list[i]);
        prefix_max[i] = cur_max;
    }

    vector<long long> res_list;
    for (int i = 1; i <= n; i++) {
        long long sum = suffix_sum[n-i];
        if (i < n && prefix_max[n-i-1] > a_list[n-i]) {
            sum = sum + prefix_max[n-i-1] - a_list[n-i];
        }
        res_list.push_back(sum);
    }

    for (int i = 0; i < n-1; i++) {
        cout << res_list[i] << " ";
    }
    cout << res_list[n-1] << endl;
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