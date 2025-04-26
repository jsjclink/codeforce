#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> l(n);
    for(int i = 0; i < n; i++) {
        cin >> l[i];
    }
    vector<int> r(n);
    for(int i = 0; i < n; i++) {
        cin >> r[i];
    }

    long long glove_sum = 0;
    priority_queue<int> max_pq;
    for(int i = 0; i < n; i++) {
        if (l[i] > r[i]) {
            glove_sum += l[i];
            max_pq.push(r[i]);
        } else {
            glove_sum += r[i];
            max_pq.push(l[i]);
        }
    }
    while (k > 1) {
        glove_sum += max_pq.top();
        max_pq.pop();
        k--;
    }
    glove_sum += 1;
    cout << glove_sum << endl;
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