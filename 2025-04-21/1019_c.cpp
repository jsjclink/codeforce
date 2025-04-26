#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n; cin >> n;
    int k; cin >> k;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int input; cin >> input;
        if (input > k) {
            v.push_back(-1);
        } else {
            v.push_back(1);
        }
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