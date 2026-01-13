#include<iostream>
#include<vector>
using namespace std;
bool solve(int n,int k){
    vector<int>arr(n,true);
    for(int i=2;i<n;i++){
        if(arr[i]){
            for(int j=i*i;j<n;j++){
                arr[i]=false;
            }
        }
    }
}
int main(){
    int n,k;
    bool ans=solve(n,k);
    
    return 0;
}