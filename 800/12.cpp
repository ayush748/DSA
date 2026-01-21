#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& b) {
    vector<int> a;
    int n = b.size();

    a.push_back(b[0]);

    for (int i = 1; i < n; i++) {
        if (b[i] >= b[i - 1]) {
            a.push_back(b[i]);
        } else {
            // Insert a smaller element to force a "drop"
            a.push_back(1);
            a.push_back(b[i]);
        }
    }

    cout << a.size() << "\n";
    for (int x : a) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        solve(b);
    }
    return 0;
}
