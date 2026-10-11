#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);
    vector<int>brr(m);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<m;i++){
        cin>>brr[i];
    }
    int i=0;
    int j=0;
    vector<int>ans;
    while(i<n && j<m){
        if(arr[i]==brr[j]){
            ans.push_back(arr[i]);
            i++;
        }else if(arr[i]<brr[j]){
            i++;
        }else{
            j++;
        }
    }
    
    return 0;
}