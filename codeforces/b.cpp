#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void solve(int n, long long k){
    long long val2 = 0;         
    long long val1 = LLONG_MIN;  
    vector<pair<long long,pair<long long,long long>>>arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        cin>>arr[i].second.first;
        cin>>arr[i].second.second;
    }
    for(int i = 0; i < n; i++){
        long long a = arr[i].first;
        long long b = arr[i].second.first;
        long long c = arr[i].second.second;
        val2 =val2+(b-1)*a;
        long long val3=a*b-c;
        if(val3>val1){
            val1=val3;
        }
    }
    if(val2>=k){
        cout<<0;
        return;
    }
    if(val1 <= 0){
        cout<<-1;
        return;
    }
    long long d=k-val2;
    long long ans=(d+val1-1)/val1;
    cout<<ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long k;
        cin>>n;
        cin>>k;
        solve(n,k);
        cout<<endl;
    }
    return 0;
}