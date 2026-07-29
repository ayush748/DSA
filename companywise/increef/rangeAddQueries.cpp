#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n,0));
    vector<vector<int>>brr;
    for(auto ans:brr){
        int row1=ans[0];
        int col1=ans[1];
        int row2=ans[2];
        int col2=ans[3];
        for(int i=row1;i<=row2;i++){
            arr[i][col1]+=1;
            if(col2+1<n){
                arr[i][col2+1]-=1;
            }
        }
        
    }
    for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                arr[i][j]+=arr[i][j-1];
            }
        }
    return 0;
}