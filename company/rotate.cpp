#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>>arr={{1,2,3},{4,5,6},{7,8,9}};
    int n=arr.size();
    int m=arr[0].size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<m;j++){
            if(i==j){
                continue;
            }
            else{
                swap(arr[i][j],arr[j][i]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m/2;j++){
            swap(arr[i][j],arr[i][n-j*-1]);
        }
    }
    return 0;
}