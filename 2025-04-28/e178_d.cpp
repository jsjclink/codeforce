#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int primes[10];

void solve() {
    int n; cin >> n;
    long long cur_sum = 0;
    long long prime_sum = 0;
    vector<int> a_list;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        a_list.push_back(a);
        cur_sum += a;
        prime_sum += primes[i];
    }
    sort(a_list.begin(), a_list.end());
    int i = n-1;
    while (i > 1 && prime_sum > cur_sum) {
        prime_sum -= primes[i];
        cur_sum -= a_list[i];
        i -= 1;
    }

    cout << n-1-i << endl;
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