#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solveRec(vector<int>& weight, vector<int>& value, int cap, int i){
    if(i==0){
        if(weight[0] <= cap) return value[0];
        else return 0;
    }
    int inc = 0;
    if(weight[i] <= cap)
        inc = value[i] + solveRec(weight, value, cap - weight[i], i - 1);
    int exc = solveRec(weight, value, cap, i - 1);
    return max(inc, exc);
}

int solveTopDown(vector<int>& weight, vector<int>& value, int cap, int i, vector<vector<int>>& dp){
    if(i==0){
        if(weight[0] <= cap) return value[0];
        else return 0;
    }
    if(dp[i][cap] != -1) return dp[i][cap];
    int inc = 0;
    if(weight[i] <= cap)
        inc = value[i] + solveTopDown(weight, value, cap - weight[i], i - 1, dp);
    int exc = solveTopDown(weight, value, cap, i - 1, dp);
    dp[i][cap] = max(inc, exc);
    return dp[i][cap];
}

int solveBottomUp(vector<int>& weight, vector<int>& value, int cap){
    int n = weight.size();
    vector<vector<int>> dp(n, vector<int>(cap+1, 0));
    for(int w = weight[0]; w <= cap; w++)
        dp[0][w] = value[0];
    for(int i = 1; i < n; i++){
        for(int w = 0; w <= cap; w++){
            int inc = 0;
            if(weight[i] <= w)
                inc = value[i] + dp[i-1][w - weight[i]];
            int exc = dp[i-1][w];
            dp[i][w] = max(inc, exc);
        }
    }
    return dp[n-1][cap];
}

int solveSpaceOpt(vector<int>& weight, vector<int>& value, int cap){
    int n = weight.size();
    vector<int> prev(cap+1, 0);
    for(int w = weight[0]; w <= cap; w++)
        prev[w] = value[0];
    for(int i = 1; i < n; i++){
        for(int w = cap; w >= 0; w--){
            int inc = 0;
            if(weight[i] <= w)
                inc = value[i] + prev[w - weight[i]];
            int exc = prev[w];
            prev[w] = max(inc, exc);
        }
    }
    return prev[cap];
}

int main(){
    int n;
    cin >> n;
    vector<int> weight(n), value(n);
    for(int i = 0; i < n; i++) cin >> weight[i];
    for(int i = 0; i < n; i++) cin >> value[i];
    int cap;
    cin >> cap;

    cout << solveRec(weight, value, cap, n-1) << endl;

    vector<vector<int>> dp(n, vector<int>(cap+1, -1));
    cout << solveTopDown(weight, value, cap, n-1, dp) << endl;

    cout << solveBottomUp(weight, value, cap) << endl;

    cout << solveSpaceOpt(weight, value, cap) << endl;

    return 0;
}