#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void solve() {
    int n; cin >> n;
    int h[1000][1000];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> h[i][j];
        }
    }
    int a[1000];
    int b[1000];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }


    long long dp[1000][2];
    dp[0][0] = 0;
    dp[0][1] = a[0];
    for (int i = 1; i < n; i++) {
        bool same_00 = false;
        bool same_01 = false;
        bool same_10 = false;
        bool same_11 = false;
        for (int j = 0; j < n; j++) {
            if (h[i-1][j] == h[i][j]) {
                same_00 = true;
            }
            if (h[i-1][j] == h[i][j] + 1) {
                same_01 = true;
            }
            if (h[i-1][j] + 1 == h[i][j]) {
                same_10 = true;
            }
            if (h[i-1][j] + 1 == h[i][j] + 1) {
                same_11 = true;
            }
        }

        dp[i][0] = -1;
        dp[i][1] = -1;
        if(!same_00 && dp[i-1][0] != -1) {
            dp[i][0] = dp[i-1][0];
        }
        if(!same_10 && dp[i-1][1] != -1) {
            if (dp[i][0] == -1 || dp[i][0] > dp[i-1][1]) {
                dp[i][0] = dp[i-1][1];
            }
        }
        if(!same_01 && dp[i-1][0] != -1) {
            dp[i][1] = dp[i-1][0] + a[i];
        }
        if(!same_11 && dp[i-1][1] != -1) {
            if(dp[i][1] == -1 || dp[i][1] > dp[i-1][1] + a[i]) {
                dp[i][1] = dp[i-1][1] + a[i];
            }
        }

    }
    long long sol = min(dp[n-1][0], dp[n-1][1]);

    dp[0][0] = 0;
    dp[0][1] = b[0];
    for (int j = 1; j < n; j++) {
        bool same_00 = false;
        bool same_01 = false;
        bool same_10 = false;
        bool same_11 = false;
        for (int i = 0; i < n; i++) {
            if (h[i][j-1] == h[i][j]) {
                same_00 = true;
            }
            if (h[i][j-1] == h[i][j] + 1) {
                same_01 = true;
            }
            if (h[i][j-1] + 1 == h[i][j]) {
                same_10 = true;
            }
            if (h[i][j-1] + 1 == h[i][j] + 1) {
                same_11 = true;
            }
        }

        dp[j][0] = -1;
        dp[j][1] = -1;
        if(!same_00 && dp[j-1][0] != -1) {
            dp[j][0] = dp[j-1][0];
        }
        if(!same_10 && dp[j-1][1] != -1) {
            if (dp[j][0] == -1 || dp[j][0] > dp[j-1][1]) {
                dp[j][0] = dp[j-1][1];
            }
        }
        if(!same_01 && dp[j-1][0] != -1) {
            dp[j][1] = dp[j-1][0] + b[j];
        }
        if(!same_11 && dp[j-1][1] != -1) {
            if(dp[j][1] == -1 || dp[j][1] > dp[j-1][1] +b[j]) {
                dp[j][1] = dp[j-1][1] + b[j];
            }
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