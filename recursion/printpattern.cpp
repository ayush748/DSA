#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&arr,vector<int>ans,int i){
    if(i==ans.size()){
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
        return ;
    }
    ans.push_back(arr[i]);
    solve(arr,ans,i+1);
    ans.pop_back();
    solve(arr,ans,i+1);
}
int main(){
    vector<int>arr={1,2,3,4,5,6};
    vector<int>ans;
    solve(arr,ans,0);

    return 0;
}