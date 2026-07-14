#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ans;

void solve(vector<int> arr, int i, int sum, int k, int total) {
    if (arr.size() == k) {
        if (sum == total)
            ans.push_back(arr);
        return;
    }

    if (i == 9)
        return;

    arr.push_back(i + 1);
    solve(arr, i + 1, sum + (i + 1), k, total);
    arr.pop_back();

    solve(arr, i + 1, sum, k, total);
}

int main() {
    int k, n;
    cin >> k >> n;

    vector<int> arr;
    solve(arr, 0, 0, k, n);

    for (auto &v : ans) {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}