#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>arr){
    int sum=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    return sum;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n-1);
        for(int i=0;i<arr.size();i++){
            cin>>arr[i];
        }
        int ans=solve(arr);
        cout<<-(ans)<<endl;
    }
    return 0;
}