#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n; cin >> n;
    int a_list[n];
    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> a_list[i];
        m = max(m, a_list[i]);
    }
    
    int res_list[n];
    bool identical = true;
    for(int i = 0; i < n; i++) {
        if (a_list[i] == m) {
            res_list[i] = 1;
        } else {
            identical = false;
            res_list[i] = 2;
        }
    }

    if (identical) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for(int i = 0; i < n; i++) {
            cout << res_list[i] << " ";
        }
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