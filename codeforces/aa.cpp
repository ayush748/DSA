#include<iostream>
#include<vector>
using namespace std;
bool solve(){
    int n,s,x;
    cin>>n>>s>>x;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    if(sum>s){
        return  false;
    }
    int val1=s-sum;
    if(val1==0){
        return true;
    }else if(val1>0){
        int val2=val1%x;
        if(val2==0){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        bool ans=solve();
        if(ans){
            cout<<"Yes";
        }else{
            cout<<"No";
        }
        cout<<endl;
    }
    return 0;
}