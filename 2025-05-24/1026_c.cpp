#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n; cin >> n;
    int d_list[n];
    for (int i = 0; i < n; i++) {
        cin >> d_list[i];
    }
    int l_list[n]; int r_list[n];
    for (int i = 0; i < n; i++) {
        cin >> l_list[i] >> r_list[i];
    }

    int hmin_list[n]; int hmax_list[n];
    for (int i = 0; i < n; i++) {
        int prev_hmin; int prev_hmax;
        if (i == 0) {
            prev_hmin = 0;
            prev_hmax = 0;
        } else {
            prev_hmin = hmin_list[i-1];
            prev_hmax = hmax_list[i-1];
        }

        if (d_list[i] != -1) {
            hmin_list[i] = max(l_list[i], prev_hmin + d_list[i]);
            hmax_list[i] = min(r_list[i], prev_hmax + d_list[i]);
        } else {
            hmin_list[i] = max(l_list[i], prev_hmin);
            hmax_list[i] = min(r_list[i], prev_hmax+1);
        }

        if (hmin_list[i] > hmax_list[i]) {
            cout << -1 << endl;
            return;
        }
    }

    int h = hmax_list[n-1];
    for (int i = n-1; i >= 0; i--) {
        if (d_list[i] != -1) {
            h = h - d_list[i];
        } else {
            if (h >= hmin_list[i] and h <= hmax_list[i]) {  
                h = h - 1;
                d_list[i] = 1;           
            } else {
                d_list[i] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << d_list[i] << " ";
    }
    cout << endl;
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