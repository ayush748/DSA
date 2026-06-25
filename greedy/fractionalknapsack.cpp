#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cap;
    cin>>cap;
    vector<int>val(n);
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    vector<int>wt(n);
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    vector<pair<int,int>>arr;
    for(int i=0;i<n;i++){
        arr.push_back({val[i],wt[i]});
    }
    sort(arr.begin(),arr.end(),[](pair<int,int>a,pair<int,int>b){
        return a.first/a.second > b.first/b.second;
    });
    int ans=0;
    for(int i=0;i<n;i++){
        if(arr[i].first<=cap){
            ans=ans+arr[i].first;
            cap=cap-arr[i].second;
        }else{
            ans=ans+(arr[i].first/arr[i].second)*cap;
            break;
        }
    }
    cout<<ans;
    return 0;
}