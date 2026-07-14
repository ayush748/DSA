#include<iostream>
#include<vector>
using namespace std;

int k;

void solve(vector<int> arr, vector<int> ans, int sum, int i){
    int n = arr.size();

    if(i == n){
        if(sum == k){
            for(auto it : ans){
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    ans.push_back(arr[i]);
    solve(arr, ans, sum + arr[i], i + 1);

    ans.pop_back();
    solve(arr, ans, sum, i + 1);
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};

    k = 10;

    vector<int> ans;
    solve(arr, ans, 0, 0);

    return 0;
}