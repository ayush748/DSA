#include<iostream>
#include<vector>
using namespace std;
vector<long long>solve(long long n,long long m,long long h,vector<long long>arr){
    vector<long long>brr(n+1,0);
    vector<long long>crr(n+1,-1);
    long long a=0;
    for (int i=0;i<m;i++){
        long long b;
        long long c;
        cin>>b;
        cin>>c;
        if (crr[b]!=a) {
            crr[b]=a;
            brr[b]=0;
        }
        brr[b]=brr[b]+c;
        if (arr[b]+brr[b]>h){
            a++; 
        }
    }
    vector<long long>drr(n+1);
    for(int i=1;i<=n;i++){
        if(crr[i]==a){
            drr[i]=arr[i]+brr[i];
        }else{
            drr[i]=arr[i];
        }
    }
    return drr;
        
}
int main() {
    int t;
    cin>>t;
    while (t--){
        long long n,m;
        long long h;
        cin>>n;
        cin>>m;
        cin>>h;
        vector<long long>arr(n+1);
        for (int i=1;i<=n;i++){
            cin >> arr[i];
        }
        vector<long long>brr=solve(n,m,h,arr);
        for (int i=1;i<=n;i++) {
            cout<<brr[i];
            if(i==n){
                cout<<endl;
            }else{
                cout<<' ';
            }
        }
       
    }
    return 0;
}
