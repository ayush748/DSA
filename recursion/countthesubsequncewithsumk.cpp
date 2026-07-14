#include <iostream>
#include <vector>
using namespace std;

int k;

int solve(vector<int>& arr, int sum, int i) {
    int n = arr.size();

    if (i == n) {
        return (sum == k);
    }

    // Take
    int take = solve(arr, sum + arr[i], i + 1);

    // Not Take
    int notTake = solve(arr, sum, i + 1);

    return take + notTake;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8};
    k = 10;

    cout << solve(arr, 0, 0);

    return 0;
}