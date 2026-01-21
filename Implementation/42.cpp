#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int solve(vector<int>arr){
    int n=arr.size();
    int i=0;
    int j=0;
    int ans=INT_MIN;
    while(i<n){
        int val=arr[i];
        if(val>ans){
            j=i;
            ans=val;
        }
        i++;
    }

    

    int sum=ans*n;
    return sum;
    

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans=solve(arr);
        cout<<ans;
        cout<<endl;
    }
    return 0;
}