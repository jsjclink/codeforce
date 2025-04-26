#include <iostream>
#include <map>

using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> a_count;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        a_count[a] += 1;
    }

    map<int, bool> fixed_front;
    for (auto it = a_count.begin(); it != a_count.end(); it++) {
        int a = it->first; int count = it->second;
        if (fixed_front[a]) {
            fixed_front[a+1] = true;
        }
        if (count >= 2) {
            fixed_front[a+1] = true;
        }
        if (count >= 4) {
            cout << "YES" << endl;
            return;
        }
    }

    map<int, bool> fixed_back;
    for (auto it = a_count.rbegin(); it != a_count.rend(); it++) {
        int a = it->first; int count = it->second;
        if (fixed_back[a+1]) {
            fixed_back[a] = true;
        }
        if (count >= 2) {
            fixed_back[a] = true;
        }
    }

    for (auto it = fixed_front.begin(); it != fixed_front.end(); it++) {
        int a = it->first; int fixed = it->second;
        if (fixed && fixed_back[a]) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
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