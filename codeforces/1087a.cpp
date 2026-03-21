#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(){
    long long n,c,k;
    cin>>n>>c>>k;
    vector<long long>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int i=0;
    
    while(i<n){
        long long val1=arr[i];
        if(val1<=c){
            long long val2=min(c-val1,k); 
            k=k-val2;
            c=c+val1+val2;          
        }
        i++;
    }
    cout<<c;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}