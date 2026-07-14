#include<iostream>
#include<vector>
using namespace std;

int k;

bool solve(vector<int> arr, vector<int> ans, int sum, int i){
    int n = arr.size();

    if(i == n){
        if(sum == k){
            for(auto it : ans){
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }

    ans.push_back(arr[i]);
    if(solve(arr, ans, sum + arr[i], i + 1)){
        return true;
    }

    ans.pop_back();
    if(solve(arr, ans, sum, i + 1)){
        return  true;
    }
    return false;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};

    k = 5;

    vector<int> ans;
    solve(arr, ans, 0, 0);

    return 0;
}