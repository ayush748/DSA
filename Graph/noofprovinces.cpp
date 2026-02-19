#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class solution{
    public:
    void dfs(int src,unordered_map<int,bool>&visited,vector<vector<int>>& arr){
        visited[src]=true;
        for(int i=0;i<arr.size();i++){
            if(!visited[i] && arr[src][i]==1){
                dfs(i,visited,arr);
            }
        }
    }
    int noofconnectedcomp(vector<vector<int>>arr){
        int n=arr.size();
        unordered_map<int,bool>visited;
        for(int i=0;i<n;i++){
            visited[i]=false;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,arr);
                cnt++;
            }
        }
        return cnt;
    }

};
int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int data;
            cin>>data;
            arr[i].push_back(data);
        }
    }
    solution obj;
    int ans=obj.noofconnectedcomp(arr);
    cout<<ans;
    return 0;
}