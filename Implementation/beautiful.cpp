#include<iostream>
#include<vector>
using namespace std;
int solve(vector<vector<int>>&arr){
    int ansi=0;
    int ansj=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(arr[i][j]==1){
                ansi=i;
                ansj=j;
            }
        }
    }

    int ans=abs(2-ansi)+abs(2-ansj);
    return ans;
}
int main(){
    vector<vector<int>>arr(5,vector<int>(5));
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>arr[i][j];
        }
    }
    int ans=solve(arr);
    cout<<ans<<endl;
    return 0;
}