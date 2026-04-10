#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solve(vector<int>& a,vector<int>& b,vector<int>& c){
    int n=a.size();
    if(n==0) return 0;

    vector<pair<int,pair<int,int>>> arr(n);

    for(int i=0;i<n;i++){
        arr[i]={b[i],{a[i],c[i]}};
    }

    sort(arr.begin(),arr.end());

    vector<int>endtime(n);
    for(int i=0;i<n;i++){
        endtime[i]=arr[i].first;
    }

    vector<int>dp(n,0);
    dp[0]=arr[0].second.second;

    for(int i=1;i<n;i++){
        int s=arr[i].second.first;
        int p=arr[i].second.second;

        int idx=upper_bound(endtime.begin(),endtime.begin()+i,s)-endtime.begin()-1;

        int take=p;
        if(idx>=0) take+=dp[idx];

        int nottake=dp[i-1];

        dp[i]=max(take,nottake);
    }

    return dp[n-1];
}

int main(){
    int n;
    cin>>n;

    vector<int>a(n),b(n),c(n);

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) cin>>c[i];

    cout<<solve(a,b,c)<<endl;
    return 0;
}
