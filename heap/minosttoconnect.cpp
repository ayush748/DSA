#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    vector<int>arr={1,8,3,5};
    int n=arr.size();
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    int ans=0;
    while(!pq.empty() && pq.size()>1){
        int val1=pq.top();
        pq.pop();
        int val2=0;
        if(!pq.empty()){
            val2=pq.top();
            pq.pop();
        }
        int val3=val1+val2;
        pq.push(val3);
        ans=ans+val1+val2;
    }
    cout<<ans<<endl;
    return 0;
}