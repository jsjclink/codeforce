#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int res = v[0];
    for(int i = 0; i+1 < v.size(); i+=2) {
        v.push_back(v[i] + v[i+1] - 1);
        res = v[i] + v[i+1] - 1;
    }
    cout << res << endl;
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