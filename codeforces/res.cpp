#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int solve(vector<int>arr){
    vector<int>brr=arr;
    bool flag=true;
    int n=arr.size();
    sort(brr.begin(),brr.end());
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]!=brr[i]){
            flag=false;
            break;
        }
    }
    if(flag){
        return -1;
    }
    int ansmax=INT_MIN;
    int ansmin=INT_MAX;
    int ans=0;
    for(int i = 0; i < n; i++){
        ansmax = max(ansmax, arr[i]);
        ansmin = min(ansmin, arr[i]);   
    }
    int l=0;
    int r=1e9;

    while(l<=r){ 
        int mid=l+(r-l)/2;
        long long left  = (long long)ansmin + mid; 
        long long right = (long long)ansmax - mid;
        bool flag = true;
        if (right<left){
            for(int i=0;i<n;i++){
                if(arr[i]>right && arr[i]<left){
                    if(arr[i]!=brr[i]){
                        flag=false;
                        break;
                    }
                }
            }
        }
        if(flag){
            ans=mid;
            l=mid+1;
        } else {
            r=mid-1;
        }
    }
    return ans;

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
        cout<<ans<<endl;
    }
    return 0;
}