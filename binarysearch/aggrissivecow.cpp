#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>arr,int i,int k){
    int n=arr.size();
    int cntcows=1;
    int last=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-last>=i){
            cntcows++;
            last=arr[i];
        }
        if(cntcows>=k){
            return true;
        }
    }
    return false;

}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=0;
    int h=arr[n-1]-arr[0];
    int k;
    while(l<=h){
        int mid=(l+h)/2;
        if(solve(arr,mid,k)){
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    cout<<h<<endl;
    return 0;
}