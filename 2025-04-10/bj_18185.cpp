#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a_list(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> a_list[i];
        if (a_list[i] > m){
            m = a_list[i];
        }
    }

    int price = 0;
    int count = 0;
    for (int h = m; h >=1; h--) {
        for (int i = 0; i < n; i++) {
            if (a_list[i] == h) {
                a_list[i] -= 1;
                count += 1;
            } else if (count > 0) {
                int tripl = count / 3;
                count %= 3;
                int doub = count / 2;
                count %= 2;
                int one = count;
                count = 0;
                price += tripl * 7 + doub * 5 + one * 3;
            }
        }
        if (count > 0) {
            int trip = count / 3;
            count %= 3;
            int doub = count / 2;
            count %= 2;
            int one = count;
            count = 0;
            price += trip * 7 + doub * 5 + one * 3;
        }
    }
    
    cout << price << endl;
    return 0;
}