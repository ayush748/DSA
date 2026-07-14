#include<iostream>
#include<vector>
using namespace std;
void solve(vector<int>&arr,int i){
    int n=arr.size();

    if(i>=n/2){
        return ;
    }
    swap(arr[i],arr[n-i-1]);
    solve(arr,i);
}
int main(){
    vector<int>arr={1,2,3,4,5,6,7};
    int n=arr.size();
    solve(arr,0);
    
    return 0;
}