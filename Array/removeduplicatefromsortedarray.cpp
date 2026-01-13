#include<iostream>
#include<vector>
using namespace std;
int approach(vector<int>arr){
    int n=arr.size();
    if(n==0){
        return 0;
    }
    int i=0;
    int j=1;
    while(j<n){
        while(j<n && arr[j]==arr[i] ){
            j++;
        }
        if(j<n){
            i++;
            arr[i]=arr[j];
            j++;
        }
    }
    return i+1;
}
int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int val=approach(arr);
    cout<<val;
    return 0;
}