#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

void print_vector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void print_array(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print_set(const set<int>& s) {
    for (int x: s) {
        cout << x << " ";
    }
    cout << endl;
}

// run without debugging: ctrl + f5
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // stdin/out
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;

    // vector
    vector<int> v = {1, 2, 3, 4, 5};
    print_vector(v);
    v.push_back(6);
    print_vector(v);
    v.pop_back();
    print_vector(v);

    // array
    int arr[5] = {1,2,3,4,5};
    print_array(arr, 5);
    
    // set
    set<int> s;
    s.insert(5);
    s.insert(1);
    s.insert(1);
    print_set(s);
    auto it = s.find(5);
    if (it != s.end()) {
        cout << "Found 5 in set" << endl;
    } else {
        cout << "5 not found" << endl;
    }

    map<int, string> m;
    m[1] = "apple";
    for (auto p: m) {
        
    }

    return 0;
}
