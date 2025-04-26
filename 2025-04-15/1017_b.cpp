#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m, l, r;
        cin >> n >> m >> l >> r;
        int end_pos = min(r, m);
        int start_pos = end_pos - m;
        cout << start_pos << " " << end_pos << endl;
    }
}