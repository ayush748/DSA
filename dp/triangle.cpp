#include<iostream>
#include<vector>
using namespace std;

int solve(int i, int j, int n, vector<vector<int>>& arr) {
    if(i == n - 1) {
        return arr[i][j];
    }

    int down = arr[i][j] + solve(i + 1, j, n, arr);
    int diagonal = arr[i][j] + solve(i + 1, j + 1, n, arr);

    return min(down, diagonal);
}

int solveMemo(int i, int j, int n, vector<vector<int>>& arr, vector<vector<int>>& dp) {
    if(i == n - 1) {
        return arr[i][j];
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int down = arr[i][j] + solveMemo(i + 1, j, n, arr, dp);
    int diagonal = arr[i][j] + solveMemo(i + 1, j + 1, n, arr, dp);

    return dp[i][j] = min(down, diagonal);
}

int solveTab(vector<vector<int>>& arr, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // base case
    for(int j = 0; j < n; j++) {
        dp[n - 1][j] = arr[n - 1][j];
    }

    for(int i = n - 2; i >= 0; i--) {
        for(int j = i; j >= 0; j--) {
            int down = arr[i][j] + dp[i + 1][j];
            int diagonal = arr[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diagonal);
        }
    }

    return dp[0][0];
}

int solveSpace(vector<vector<int>>& arr, int n) {
    vector<int> front(n, 0);
    vector<int> cur(n, 0);

    // base case
    for(int j = 0; j < n; j++) {
        front[j] = arr[n - 1][j];
    }

    for(int i = n - 2; i >= 0; i--) {
        for(int j = i; j >= 0; j--) {
            int down = arr[i][j] + front[j];
            int diagonal = arr[i][j] + front[j + 1];
            cur[j] = min(down, diagonal);
        }
        front = cur;
    }

    return front[0];
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Recursion: " << solve(0, 0, n, arr) << endl;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << "Memoization: " << solveMemo(0, 0, n, arr, dp) << endl;

    cout << "Tabulation: " << solveTab(arr, n) << endl;
    cout << "Space Optimization: " << solveSpace(arr, n) << endl;

    return 0;
}