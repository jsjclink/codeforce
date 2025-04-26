#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int count = 0;
    int prev = 0;
    int state_101 = 0;
    for (int i = 0; i < n; i++) {
        int input = s[i] - '0';
        if (input != prev) {
            count++;
        }
        count++;
        prev = input;

        switch (state_101)
        {
        case 0:
            if (input == 1){ 
                state_101++;
            }
            break;
        case 1:
            if (input == 0) {
                state_101++;
            }
            break;
        case 2:
            if (input == 1) {
                state_101++;
            }
            break;
        }   
    }
    if (state_101 == 3) {
        count = count - 2;
    }
    if (state_101 == 2) {
        count = count - 1;
    }

    cout << count << endl;
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