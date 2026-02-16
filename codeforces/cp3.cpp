#include<iostream>
#include<vector>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>dp(7);
    int i=0;
    while(i<=6){
        if(arr[0]==i){
            dp[i] = 0;
        }else{
            dp[i] = 1;
        }
        i++;
    }
    i=1;
    while(i<n){
        vector<int>brr(7, n);
        int j=1;
        while(j<=6){
            int val;
            if(arr[i]==j){
                val=0;
            }else{
                val=1;
            }
            for(int k=1;k<=6;k++){
                if((j!=k)&&(j+k!=7)){
                    if(dp[k]+val < brr[j]){
                        brr[j]=dp[k]+val;
                    }
                }
            }
            j++;
        }
        dp=brr;
        i++;
    }
    int ans=dp[1];
    i=2;
    while(i<=6){
        if(dp[i]<ans){
            ans=dp[i];
        }
        i++;
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
