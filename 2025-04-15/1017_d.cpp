#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

void solve() {
    string p, s;
    cin >> p >> s;
    vector<pair<char, int>> cont_count;
    char prev_p = 'n';
    int cur_cont = 0;
    for(int i = 0; i < p.size(); i++) {
        if (prev_p == 'n' || prev_p == p[i]) {
            cur_cont++;
        } else {
            cont_count.push_back({prev_p, cur_cont});
            cur_cont = 1;
        }
        prev_p = p[i];
    }
    cont_count.push_back({prev_p, cur_cont});

    int cont_i = 0;
    cur_cont = 0;
    for(int i = 0; i < s.size(); i++) {
        if(cont_count[cont_i].first == s[i]) {
            cur_cont++;
            if (cont_count[cont_i].second*2 < cur_cont) {
                cout << "NO" << endl;
                return;
            }
        } else {
            if(cont_count[cont_i].second > cur_cont) {
                cout << "NO" << endl;
                return;
            }
            cur_cont = 1;
            cont_i++;
            if(cont_i > cont_count.size() - 1) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    if(cont_count[cont_i].second > cur_cont) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++) {
        solve();
    }
}