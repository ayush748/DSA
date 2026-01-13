#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    if (n == k) {
        cout<<0<<endl;
        return;
    }

    if (n < k) {
        cout << -1 << "\n";
        return;
    }

    vector<int> v;
    v.push_back(n);

    int t = 0;

    while (!v.empty()) {
        t++;
        vector<int> next_v;
        bool found = false;

        for (int x : v) {
            int a = x / 2;
            int b = (x + 1) / 2;

            if (a == k || b == k) {
                found = true;
                break;
            }

            if (a > k) next_v.push_back(a);
            if (b > k) next_v.push_back(b);
        }

        if (found) {
            cout << t << "\n";
            return;
        }

        if (next_v.empty()) {
            break;
        }

        sort(next_v.begin(), next_v.end());
        int sz = unique(next_v.begin(), next_v.end()) - next_v.begin();
        next_v.resize(sz);

        v = next_v;
    }

    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}