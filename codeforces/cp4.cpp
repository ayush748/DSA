#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
using namespace std;
bool f(long long a1,long long b1,long long c1,long long a2,long long b2,long long c2)
{
    long long a=a1-a2,b=b1-b2,c=c1-c2;
    if(a==0)
    return b==0;
    return b*b<4LL*a*c;
}

void solve()
{
    int n;
    cin>>n;
    vector<pair<pair<long long,pair<long long,long long>>,int>>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first.first;
        cin>>arr[i].first.second.first;
        cin>>arr[i].first.second.second;
        arr[i].second=i;
    }
    sort(arr.begin(),arr.end());
    vector<int>l(n,1);
    vector<int>r(n,1);
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(f(arr[i].first.first,arr[i].first.second.first,arr[i].first.second.second,arr[j].first.first,arr[j].first.second.first,arr[j].first.second.second)){
                l[i]=max(l[i],l[j]+1);
            }
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(f(arr[i].first.first,arr[i].first.second.first,arr[i].first.second.second,arr[j].first.first,arr[j].first.second.first,arr[j].first.second.second)){
                r[i]=max(r[i],r[j]+1);
            }
        }
    }
    for(int i=0;i<n;i++){
        ans[arr[i].second]=l[i]+r[i]-1;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i];
        if(i+1<n){
            cout<<" ";
        }
    }
}
int main()
{
    map<int,int>mp1;
    unordered_map<int,int>mp2;
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}
