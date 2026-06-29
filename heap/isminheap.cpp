#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool flag=true;
    for(int i=0;i<n;i++){
        int l=2*i+1;
        int r=2*i+2;
        if(l<n && arr[i]>arr[l]){
            flag=false;
            break;
        }
        if(r<n && arr[i]>arr[r]){
            flag=false;
            break;
        }
    }
    
    return 0;
}