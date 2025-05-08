#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
    int n;
    long long k; 
    cin >> n >> k;
    string s; cin >> s;
 
    long long a_list[n];
    for (int i = 0; i < n; i++) {
        cin >> a_list[i];
        if(s[i] == '0') a_list[i] = -1e18;
    }
    
    long long max_array_sum[n];
    max_array_sum[0] = a_list[0];
    long long max = a_list[0];
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            max_array_sum[i] = -1e18;
            continue;
        }
        
        if (max_array_sum[i-1] < 0) {
            max_array_sum[i] = a_list[i];
        } else {
            max_array_sum[i] = max_array_sum[i-1] + a_list[i];
        }
        
        if (max_array_sum[i] > max) {
            max = max_array_sum[i];
        }
    }
 
    if (max == k) {
        cout << "Yes" << endl;
        for(int i = 0; i < n; i++) {
            cout << a_list[i] << " ";
        }
        cout << endl;
        return;
    }
    if (max > k) {
        cout << "No" << endl;
        return;
    }
 
    long long max_array_sum_rev[n];
    max_array_sum_rev[n-1] = a_list[n-1];
    for (int i = n-2; i >= 0; i--) {
        if (s[i] == '0') {
            max_array_sum_rev[i] = -1e18;
            continue;
        }
        
        if (max_array_sum_rev[i+1] < 0) {
            max_array_sum_rev[i] = a_list[i];
        } else {
            max_array_sum_rev[i] = max_array_sum_rev[i+1] + a_list[i];
        }
    }
 
    int target_pos = -1;
    for (int i = 0; i < n; i++) {
        if(s[i] == '0') {
            target_pos = i;
            break;
        }
    }
 
    if (target_pos == -1) {
        cout << "No" << endl;
        return;
    }
    
    a_list[target_pos] = k;
    if (target_pos > 0 && max_array_sum[target_pos-1] > 0) {
        a_list[target_pos] = a_list[target_pos] - max_array_sum[target_pos-1];
    }
    if (target_pos < n-1 && max_array_sum_rev[target_pos+1] > 0) {
        a_list[target_pos] = a_list[target_pos] - max_array_sum_rev[target_pos+1];
    }
 
    cout << "Yes" << endl;
    for(int i = 0; i < n; i++) {
        cout << a_list[i] << " ";
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
