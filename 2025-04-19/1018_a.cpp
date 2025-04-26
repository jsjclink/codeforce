#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> sol_rev;
    int cur_min = 1;
    int cur_max = n;
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] == '<') {
            sol_rev.push_back(cur_min);
            cur_min++;
        } else {
            sol_rev.push_back(cur_max);
            cur_max--;
        }
    }
    sol_rev.push_back(cur_min);
    for (int i = sol_rev.size()-1; i >=0; i--) {
        cout << sol_rev[i];
        if (i != 0) {
            cout << ' ';
        }
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