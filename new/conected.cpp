#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
int main(){
    vector<vector<int>>arr={
        {1,1,0},{1,1,0},{0,0,1}
    };
    int n=arr.size();
    int m=arr[0].size();
    unordered_map<int,vector<int>>mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i!=j && arr[i][j]!=0){
                mp[i].push_back(j);
                mp[j].push_back(i);
            }
        }
    }
    return 0;
}