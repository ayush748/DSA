#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>>arr={
        {1,2,-1},
        {4,0,6},
        {7,8,9}
    };
    
    int n=arr.size();
    int m=arr[0].size();
    vector<int>row(n);
    vector<int>col(m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                row[i]=1;
                col[j]=1;

            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i] || col[j]){
                arr[i][j]=0;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;

    }

    return 0;
}