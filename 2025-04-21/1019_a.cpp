#include <iostream>
#include <set>

using namespace std;

void solve() {
    int n; cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int input; cin >> input;
        s.insert(input);
    }
    cout << s.size() << endl;
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