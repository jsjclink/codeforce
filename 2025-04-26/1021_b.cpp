#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <climits>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a_list;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        a_list.push_back(a);
    }
    std::sort(a_list.begin(), a_list.end());

    vector<long long> prefix_sum;
    long long cur_sum = 0;
    for (int i = 0; i < n; i++) {
        cur_sum += a_list[i];
        prefix_sum.push_back(cur_sum);
    }

    map<int, long long> fx_map;
    for (int i = 0; i < n; i++) {
        int x = a_list[i];
        
        int nk = n-k;
        int l = max(0, i-nk); int r = min(n-nk, i);
        while (l < r) {
            int mid = (l + r) / 2;
            if (abs(a_list[mid] - x) > abs(a_list[mid + nk] - x)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        r = l + nk - 1;
        
        int left = i - l + 1;
        int right = r - i;

        long long li_sum = prefix_sum[i];
        if (l > 0) {
            li_sum = prefix_sum[i] - prefix_sum[l-1];
        }

        long long fx = left * x - li_sum + (prefix_sum[r] - prefix_sum[i]) - right * x;
        fx_map[x] = fx;
    }

    long long min_fx = LLONG_MAX;
    int min_count = 0;
    for (auto it = fx_map.begin(); it != fx_map.end(); it++) {
        int x = it->first; int fx = it->second;
        if (fx == min_fx) {
            min_count += 1;
        }
        if (fx < min_fx) {
            min_fx = fx;
            min_count = 1;
        }
    }

    cout << min_count << endl;
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