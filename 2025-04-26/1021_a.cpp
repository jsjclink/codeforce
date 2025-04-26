#include <iostream>

using namespace std;

void solve() {
    string s; cin >> s;
    int count[10] = {0};
    for (int i = 0; i < 10; i++) {
        count[s[i] - '0'] += 1;
    }
    string sol = "";
    for (int i = 0; i < 10; i++) {
        for (int j = 10 - (i + 1); j < 10; j++) {
            if (count[j] > 0) {
                count[j] -= 1;
                sol += (char)(j + '0');
                break;
            }
        }
    }
    cout << sol << endl;
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