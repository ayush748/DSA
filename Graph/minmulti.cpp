#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int s,e;
    queue<pair<int,int>>q;
    vector<int>dist(n,1e9);
    dist[s]=0;
    q.push({s,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int node=it.first;
        int steps=it.second;
        for(auto it:arr){
            int nums=it*node;
            if(steps+1<dist[nums]){
                dist[nums]=steps+1;
                if(nums==e){
                    return steps+1;
                }
                q.push({nums,steps+1});
            }
        }
    }
    cout<<-1;
    return 0;
}