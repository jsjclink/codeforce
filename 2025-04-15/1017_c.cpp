#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vector<int> permutation;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int input;
                cin >> input;
                
                if (i == 0 || (i == n-1 && j > 0)) {
                    permutation.push_back(input);
                    sum = sum + input;
                }
            }
        }

        cout << 2*n*(2*n+1)/2 - sum << " ";
        for (int i = 0; i < 2*n-1; i++) {
            cout << permutation[i];
            if (i != 2*n-2) {
                cout << " ";
            }
        }
        cout << endl;
    }
}