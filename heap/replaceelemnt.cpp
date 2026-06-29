#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int main(){
    vector<int>arr={20,15,26,2,98,6};
    int n=arr.size();
    priority_queue<int,vector<int>,greater<int>>pq;
    
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    int cnt=1;
    map<int,int>mp;
    while(!pq.empty()){
        int val=pq.top();
        mp[val]=cnt;
        cnt++;
        pq.pop();        
    }
    for(int i=0;i<n;i++){
        cout<<mp[arr[i]]<<" ";
    }
    
    return 0;
}