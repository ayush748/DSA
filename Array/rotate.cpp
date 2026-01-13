#include<iostream>
#include<vector>
using namespace std;
void function(vector<vector<int>>&arr,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    function(arr,n,m);
    return 0;
}