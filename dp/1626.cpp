#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int solve(vector<pair<int,int>>arr,int i,stack<pair<int,int>>st){
    if(i>=arr.size()){
        return 0;
    }
    if(st.empty()){

        st.push(arr[i]);
        return arr[i].second;
    }
    // int take=0;
    // if(st.top().first==arr[i].first){
    //     stack<pair<int,int>> temp=st;
    //     temp.push(arr[i]);
    //     take=arr[i].second+solve(arr,i+1,st);
    // }
    
    // if(st.top().first<arr[i].first){
    //     if(st.top().second<arr[i].second){
    //         st.push(arr[i]);
    //         take=arr[i].second+solve(arr,i+1,st);
    //     }
    // }
    // int nottake=0+solve(arr,i+1,st);
    
    return max(take,nottake);

    
}
int main(){
    vector<int>scores={1,3,5,10,15};
    vector<int>ages={1,2,3,4,5};
    vector<pair<int,int>>arr;
    stack<pair<int,int>>st;
    int n=scores.size();
    for(int i=0;i<n;i++){
        arr.push_back({ages[i],scores[i]});
    }
    sort(arr.begin(),arr.end());
    int ans=solve(arr,0,st);
    return 0;
}