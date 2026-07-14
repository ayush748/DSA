#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> brr;
void solve(vector<int>& arr, vector<int>& ans, int i, int t) {
    if (t == 0) {
        brr.push_back(ans);
        return;
    }

    if (i == arr.size() || t < 0) {
        return;
    }

    for (int j = i; j < arr.size(); j++) {
        if (j > i && arr[j] == arr[j - 1]) {
            continue;
        }

        if (arr[j] > t) {
            break;
        }

        ans.push_back(arr[j]);
        solve(arr, ans, j + 1, t - arr[j]);
        ans.pop_back();
    }
}

int main() {
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    sort(arr.begin(), arr.end());

    vector<int> ans;
    int t = 8;

    solve(arr, ans, 0, t);

    for (auto &v : brr) {
        for (int x : v) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}