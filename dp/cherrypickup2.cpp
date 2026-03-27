#include <iostream>
#include <vector>
using namespace std;
int solve(int i, int j, int k, int n, int m, vector<vector<int>>& arr){
    if (j < 0 || j >= m || k < 0 || k >= m){
        return -1e9;
    }
    if (i == n - 1) {
        if (j == k) return arr[i][j];
        else return arr[i][j] + arr[i][k];
    }
    int maxi = -1e9;
    int curr;
    if (j == k){
        curr = arr[i][j];
    }
    else{
        curr = arr[i][j] + arr[i][k];
    }

    for (int a = -1; a <= 1; a++) {
        for (int b = -1; b <= 1; b++) {
            int c = curr + solve(i + 1, j + a, k + b, n, m, arr);
            maxi = max(maxi, c);
        }
    }
    return maxi;
}
int main() {
    vector<vector<int>> arr = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };
    int n = arr.size();
    int m = arr[0].size();
    cout << solve(0, 0, m - 1, n, m, arr);
    return 0;
}