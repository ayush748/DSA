
// #include <bits/stdc++.h>
// using namespace std;
// class StockBuySell{
// int getAns(vector& Arr, int n, int ind, int buy, int cap, vector>>& dp) {
//     // Base case
//     if (ind == n || cap == 0) return 0;

//     // Check if the result is already computed
//     if (dp[ind][buy][cap] != -1)
//         return dp[ind][buy][cap];

//     int profit;

//     if (buy == 0) { // We can buy the stock
//         profit = max(0 + getAns(Arr, n, ind + 1, 0, cap, dp),
//                      -Arr[ind] + getAns(Arr, n, ind + 1, 1, cap, dp));
//     }

//     if (buy == 1) { // We can sell the stock
//         profit = max(0 + getAns(Arr, n, ind + 1, 1, cap, dp),
//                      Arr[ind] + getAns(Arr, n, ind + 1, 0, cap - 1, dp));
//     }

//     // Store the result in the DP array and return
//     return dp[ind][buy][cap] = profit;
// }

// int maximumProfit(vector& prices, int n, int k) {
//     // Creating a 3D DP array of size [n][2][k+1]
//     vector>> dp(n,
//                                     vector>(2, vector(k + 1, -1)));

//     return getAns(prices, n, 0, 0, k, dp);
// }

// int main() {
//     vector prices = {3, 3, 5, 0, 0, 3, 1, 4};
//     int n = prices.size();
//     int k = 2;

//     cout << "The maximum profit that can be generated is " << maximumProfit(prices, n, k) << endl;
//     return 0;
// }



#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>arr,int i,int buy,int cap){
    
    if(i==arr.size() || cap==0){
        return 0;
    }
    long profit;
    if(buy==0){
        profit=max(-arr[i]+solve(arr,i+1,1,cap),0+solve(arr,i+1,0,cap));
    }else{
        profit=max(arr[i]+solve(arr,i+1,0,cap-1),0+solve(arr,i+1,1,cap));
    }
    return profit;

}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=solve(arr,0,0,2);
    cout<<ans<<endl;
    return 0;
}