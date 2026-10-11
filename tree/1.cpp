#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
void solve() {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<int,int>mp;
    for(auto val:arr){
        mp[val]++;
    }
    priority_queue<pair<int,int>>pq;
    for(auto val:mp){
        pq.push({val.second,val.first});
    }
    int prev=-1;
    int sum=0;
    int i=1;
    while(!pq.empty()){
        auto front=pq.top();
        pq.pop();
        if(front.second!=prev){
            sum=sum+front.second;
            prev=front.second;
            front.first--;
            if(front.first>0){
                pq.push(front);
            }
        }else{
            if(pq.empty()){
                sum+=front.second;
                break;
            }
            auto second=pq.top();
            pq.pop();
            sum+=second.second;
            prev=second.second;
            second.first--;
            if(second.first>0){
                pq.push(second);
            }
            pq.push(front);
        }
    }
    cout<<sum<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}