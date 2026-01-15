#include<iostream>
#include<vector>
using namespace std;
const int score[10][10]={
    {1,1,1,1,1,1,1,1,1,1},
    {1,2,2,2,2,2,2,2,2,1},
    {1,2,3,3,3,3,3,3,2,1},
    {1,2,3,4,4,4,4,3,2,1},
    {1,2,3,4,5,5,4,3,2,1},
    {1,2,3,4,5,5,4,3,2,1},
    {1,2,3,4,4,4,4,3,2,1},
    {1,2,3,3,3,3,3,3,2,1},
    {1,2,2,2,2,2,2,2,2,1},
    {1,1,1,1,1,1,1,1,1,1}
};
long long solve(vector<vector<char>>arr){
    int n=arr.size();
    int m=arr[0].size();
    long long ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='X'){
                ans=ans+score[i][j];
            }
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<char>>arr(10,vector<char>(10));
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cin>>arr[i][j];
            }
        }

        long long ans=solve(arr);
        cout<<ans<<endl;
    }
    return 0;
}