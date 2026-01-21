#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solve(vector<int>&arr){
    int a=1;
    int b=1;
    int i=1;
    int n=arr.size();
    while(i<n){
        if(arr[i]==arr[i-1]){
            i++;
            continue;
        }
        if(arr[i]==arr[i-1]+1){
            b++;
        }else{
            a=max(a,b);
            b=1;
        }
        i++;
    }
    return max(a,b);
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int ans=solve(arr);
        cout<<ans<<endl;
    }
    return 0;
}
