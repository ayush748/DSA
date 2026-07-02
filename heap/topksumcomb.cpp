#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
vector<int>solve(vector<int>arr,vector<int>brr,int k){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());
    priority_queue<pair<int,pair<int,int>>>pq;
    set<pair<int,int>>vis;
    pq.push({arr[n-1]+brr[n-1],{n-1,n-1}});
    vis.insert({n-1,n-1});
    vector<int>ans;
    while (k-- && !pq.empty()) {
            auto cur=pq.top();
            pq.pop();
            int sum=cur.first;
            int i=cur.second.first;
            int j=cur.second.second;
            ans.push_back(sum);
            if (i-1>= 0 && !vis.count({i-1,j})){
                pq.push({arr[i-1]+brr[j],{i-1,j}});
                vis.insert({i-1,j});
            }
            if (j-1>=0 && !vis.count({i,j-1})) {
                pq.push({arr[i]+brr[j-1],{i,j-1}});
                vis.insert({i,j-1});
            }
        }
        return ans;
}
int main(){
    int n;
    int k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>brr(n);
    for(int i=0;i<n;i++){
        cin>>brr[i];
    }
    int k;
    cin>>k;
    vector<int>ans=solve(arr,brr,k);


    return 0;
}